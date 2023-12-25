#ifndef FIREEMPLOYEEDIALOG_H
#define FIREEMPLOYEEDIALOG_H

#include <QDialog>

class QLineEdit;
class QDialogButtonBox;

class FireEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    FireEmployeeDialog(QWidget *parent = nullptr);

    int getEmployeeNumber() const;

private:
    QLineEdit *employeeNumberEdit;
    QDialogButtonBox *buttonBox;
};

#endif // FIREEMPLOYEEDIALOG_H
