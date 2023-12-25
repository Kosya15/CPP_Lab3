#ifndef HIREEMPLOYEEDIALOG_H
#define HIREEMPLOYEEDIALOG_H

#include <QDialog>

class QLineEdit;
class QDialogButtonBox;

class HireEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    HireEmployeeDialog(QWidget *parent = nullptr);

    QString getFullName() const;
    int getAge() const;
    QString getSex() const;
    QString getAddress() const;
    QString getPassportData() const;
    QString getJobCode() const;

private:
    QLineEdit *fullNameEdit;
    QLineEdit *ageEdit;
    QLineEdit *sexEdit;
    QLineEdit *addressEdit;
    QLineEdit *passportDataEdit;
    QLineEdit *jobCodeEdit;

    QDialogButtonBox *buttonBox;
};

#endif // HIREEMPLOYEEDIALOG_H
