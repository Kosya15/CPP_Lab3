// hireemployeedialog.cpp
#include "HireEmployeeDialog.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

HireEmployeeDialog::HireEmployeeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Hire a new employee");

    QFormLayout *formLayout = new QFormLayout(this);

    fullNameEdit = new QLineEdit(this);
    ageEdit = new QLineEdit(this);
    sexEdit = new QLineEdit(this);
    addressEdit = new QLineEdit(this);
    passportDataEdit = new QLineEdit(this);
    jobCodeEdit = new QLineEdit(this);

    formLayout->addRow("Full name:", fullNameEdit);
    formLayout->addRow("Age:", ageEdit);
    formLayout->addRow("Sex:", sexEdit);
    formLayout->addRow("Address:", addressEdit);
    formLayout->addRow("Passport data:", passportDataEdit);
    formLayout->addRow("Job code:", jobCodeEdit);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                     Qt::Horizontal, this);
    formLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

QString HireEmployeeDialog::getFullName() const
{
    return fullNameEdit->text();
}

int HireEmployeeDialog::getAge() const
{
    return ageEdit->text().toInt();
}

QString HireEmployeeDialog::getSex() const
{
    return sexEdit->text();
}

QString HireEmployeeDialog::getAddress() const
{
    return addressEdit->text();
}

QString HireEmployeeDialog::getPassportData() const
{
    return passportDataEdit->text();
}

QString HireEmployeeDialog::getJobCode() const
{
    return jobCodeEdit->text();
}
