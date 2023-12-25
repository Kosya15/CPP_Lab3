// promoteemployeedialog.cpp
#include "promoteemployeedialog.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

PromoteEmployeeDialog::PromoteEmployeeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Promote an employee");

    QFormLayout *formLayout = new QFormLayout(this);

    employeeNumberEdit = new QLineEdit(this);
    promotionAmountEdit = new QLineEdit(this);

    formLayout->addRow("Employee Number:", employeeNumberEdit);
    formLayout->addRow("Which promotion:", promotionAmountEdit);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                     Qt::Horizontal, this);
    formLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

int PromoteEmployeeDialog::getEmployeeNumber() const
{
    return employeeNumberEdit->text().toInt();
}

int PromoteEmployeeDialog::getPromotionAmount() const
{
    return promotionAmountEdit->text().toInt();
}
