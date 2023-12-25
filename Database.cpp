// Database.cpp
#include "Database.h"
#include <QDebug>
#include <QMessageBox>
#include <stdexcept>
#include <QFile>
#include <QTextStream>

Database::Database() {
    mNextSlot = 0;
    mNextEmployeeNumber = kFirstEmployeeNumber;
}

Database::~Database() {}

Employee& Database::addEmployee(const QString& inFullName, int inAge, const QString& inSex, const QString& inAddress, int inPassportData, int inJobCode) {
    if (mNextSlot >= kMaxEmployees) {
        QMessageBox::critical(nullptr, "Error", "There is no more room to add the new employee!");
        throw std::out_of_range("Employee array is full");
    }

    if (inJobCode < 1 || inJobCode > 6) {
        QMessageBox::critical(nullptr, "Error", "Unable to recognize job post by this job code!");
        throw std::invalid_argument("Invalid job code");
    }

    if (inAge < 17 || inAge > 65) {
        QMessageBox::critical(nullptr, "Error", "Cannot add the employee with not employable age!");
        throw std::out_of_range("Employee age out of range");
    }

    if (inSex != "Male" && inSex != "Female") {
        QMessageBox::critical(nullptr, "Error", "Cannot add the employee with unknown sex! Please enter information correctly.");
        throw std::invalid_argument("Invalid sex");
    }

    Employee& theEmployee = mEmployees[mNextSlot++];
    theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
    theEmployee.setFullName(inFullName);
    theEmployee.setAge(inAge);
    theEmployee.setSex(inSex);
    theEmployee.setPassportData(inPassportData);
    theEmployee.setAddress(inAddress);
    theEmployee.setJobCode(inJobCode);
    theEmployee.setSalary();
    theEmployee.hire();
    return theEmployee;
}

Employee& Database::getEmployee(int inEmployeeNumber) {
    for (int i = 0; i < mNextSlot; i++) {
        if (mEmployees[i].getEmployeeNumber() == inEmployeeNumber) {
            return mEmployees[i];
        }
    }

    qCritical() << "No employee with employee number " << inEmployeeNumber;
    throw std::out_of_range("Employee not found");
}

void Database::displayAll() {
    for (int i = 0; i < mNextSlot; i++) {
        mEmployees[i].display();
    }
}

void Database::displayCurrent() {
    for (int i = 0; i < mNextSlot; i++) {
        if (mEmployees[i].getIsHired()) {
            mEmployees[i].display();
        }
    }
}

void Database::displayFormer() {
    for (int i = 0; i < mNextSlot; i++) {
        if (!mEmployees[i].getIsHired()) {
            mEmployees[i].display();
        }
    }
}

void Database::saveToFile(const QString& filename) {
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "-------------------------" << Qt::endl;
        out << "List of All Employees:" << Qt::endl;
        displayAllToFile(out);
        out << "-------------------------" << Qt::endl;

        file.close();
    } else {
        qDebug() << "Error opening file for writing.";
    }
}

void Database::displayAllToFile(QTextStream& out)  {
    for (int i = 0; i < mNextSlot; ++i) {
        mEmployees[i].displayToFile(out);
    }
}
