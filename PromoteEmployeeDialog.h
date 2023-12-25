// promoteemployeedialog.h
#ifndef PROMOTEEMPLOYEEDIALOG_H
#define PROMOTEEMPLOYEEDIALOG_H

#include <QDialog>

class QLineEdit;
class QDialogButtonBox;

class PromoteEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    PromoteEmployeeDialog(QWidget *parent = nullptr);

    int getEmployeeNumber() const;
    int getPromotionAmount() const;

private:
    QLineEdit *employeeNumberEdit;
    QLineEdit *promotionAmountEdit;

    QDialogButtonBox *buttonBox;
};

#endif // PROMOTEEMPLOYEEDIALOG_H
