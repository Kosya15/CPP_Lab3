#include "mainwindow.h"
#include "Database.h"
#include "HireEmployeeDialog.h"
#include "FireEmployeeDialog.h"
#include "PromoteEmployeeDialog.h"
#include "DemoteEmployeeDialog.h"
#include "ListEmployeeDialog.h"
#include <QVBoxLayout>
#include <QFile>
#include <QDataStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createButtons();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(hireButton);
    layout->addWidget(fireButton);
    layout->addWidget(promoteButton);
    layout->addWidget(demoteButton);
    layout->addWidget(listAllButton);
    layout->addWidget(saveButton);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setWindowTitle("Information system of the library");
}

MainWindow::~MainWindow() {}

void MainWindow::createButtons()
{
    hireButton = new QPushButton("Hire a new employee", this);
    connect(hireButton, SIGNAL(clicked()), this, SLOT(hireEmployee()));

    fireButton = new QPushButton("Fire an employee", this);
    connect(fireButton, SIGNAL(clicked()), this, SLOT(fireEmployee()));

    promoteButton = new QPushButton("Promote an employee", this);
    connect(promoteButton, SIGNAL(clicked()), this, SLOT(promoteEmployee()));

    demoteButton = new QPushButton("Demote an employee", this);
    connect(demoteButton, SIGNAL(clicked()), this, SLOT(demoteEmployee()));

    listAllButton = new QPushButton("List all employees", this);
    connect(listAllButton, SIGNAL(clicked()), this, SLOT(listAllEmployees()));

    saveButton = new QPushButton("Save", this);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveData()));
}

void MainWindow::hireEmployee()
{
    HireEmployeeDialog hireDialog(this);

    if (hireDialog.exec() == QDialog::Accepted) {
        QString fullName = hireDialog.getFullName();
        int age = hireDialog.getAge();
        QString sex = hireDialog.getSex();
        QString address = hireDialog.getAddress();
        int passportData = hireDialog.getPassportData().toInt();
        int jobCode = hireDialog.getJobCode().toInt();

        try {
            mDatabase.addEmployee(fullName, age, sex, address, passportData, jobCode);
            QMessageBox::information(nullptr, "Success", "Employee added successfully!");

        } catch (const std::exception &e) {
            QMessageBox::critical(nullptr, "Error", QString("Failed to add employee: %1").arg(e.what()));
        }
    }
}

void MainWindow::fireEmployee()
{
    FireEmployeeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        int employeeNumber = dialog.getEmployeeNumber();
        try {
            Employee& employee = mDatabase.getEmployee(employeeNumber);
            if (employee.getIsHired()) {
                employee.fire();
                QMessageBox::information(nullptr, "Success", "Employee fired successfully!");
            } else {
                QMessageBox::critical(nullptr, "Error", "Employee is already fired!");
            }
        } catch (const std::exception& e) {
            QMessageBox::critical(nullptr, "Error", QString("Failed to fire employee: %1").arg(e.what()));
        }
    }
}

void MainWindow::promoteEmployee()
{
    PromoteEmployeeDialog promoteDialog(this);

    if (promoteDialog.exec() == QDialog::Accepted) {
        int employeeNumber = promoteDialog.getEmployeeNumber();
        int promotionAmount = promoteDialog.getPromotionAmount();

        try {
            Employee& employee = mDatabase.getEmployee(employeeNumber);
            if(employee.getIsHired()){
                employee.promote(promotionAmount);
                QMessageBox::information(nullptr, "Success", "Employee promoted successfully!");
            } else{
                QMessageBox::critical(nullptr, "Error", "Employee is fired! Cannot to promote!");
            }
        } catch (const std::exception &e) {
            QMessageBox::critical(nullptr, "Error", QString("Failed to promote employee: %1").arg(e.what()));
        }
    }
}

void MainWindow::demoteEmployee()
{
    DemoteEmployeeDialog demoteDialog(this);

    if (demoteDialog.exec() == QDialog::Accepted) {
        int employeeNumber = demoteDialog.getEmployeeNumber();
        int demotionAmount = demoteDialog.getDemotionAmount();

        try {
            Employee& employee = mDatabase.getEmployee(employeeNumber);
            if(employee.getIsHired()){
                employee.demote(demotionAmount);
                QMessageBox::information(nullptr, "Success", "Employee demoted successfully!");
            } else {
                QMessageBox::critical(nullptr, "Error", "Employee is fired! Cannot to demote!");
            }
        } catch (const std::exception &e) {
            QMessageBox::critical(nullptr, "Error", QString("Failed to demote employee: %1").arg(e.what()));
        }
    }
}

void MainWindow::listAllEmployees() {
    ListEmployeeDialog *listDialog = new ListEmployeeDialog(this);
    listDialog->setAttribute(Qt::WA_DeleteOnClose, true);
    listDialog->show();
}


void MainWindow::saveData() {
    QString defaultFileName = QDir::currentPath() + "/save.txt";

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Save Data",
                                                    defaultFileName,
                                                    "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        mDatabase.displayAllToFile(out);

        file.close();
        QMessageBox::information(this, "Save Successful", "Data has been saved successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the file for writing.");
    }
}
