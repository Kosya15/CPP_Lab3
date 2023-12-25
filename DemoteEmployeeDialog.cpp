#include "DemoteEmployeeDialog.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

DemoteEmployeeDialog::DemoteEmployeeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Demote an employee");

    QFormLayout *formLayout = new QFormLayout(this);

    employeeNumberEdit = new QLineEdit(this);
    demotionAmountEdit = new QLineEdit(this);

    formLayout->addRow("Employee Number:", employeeNumberEdit);
    formLayout->addRow("Which demotion:", demotionAmountEdit);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                     Qt::Horizontal, this);
    formLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

int DemoteEmployeeDialog::getEmployeeNumber() const
{
    return employeeNumberEdit->text().toInt();
}

int DemoteEmployeeDialog::getDemotionAmount() const
{
    return demotionAmountEdit->text().toInt();
}
