#ifndef DEMOTEEMPLOYEEDIALOG_H
#define DEMOTEEMPLOYEEDIALOG_H

#include <QDialog>

class QLineEdit;
class QDialogButtonBox;

class DemoteEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    DemoteEmployeeDialog(QWidget *parent = nullptr);

    int getEmployeeNumber() const;
    int getDemotionAmount() const;

private:
    QLineEdit *employeeNumberEdit;
    QLineEdit *demotionAmountEdit;

    QDialogButtonBox *buttonBox;
};

#endif // DEMOTEEMPLOYEEDIALOG_H
