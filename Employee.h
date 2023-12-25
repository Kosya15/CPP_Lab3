#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QTextStream>

class Employee {
public:
    Employee();

    void hire();
    void fire();
    void promote(int raiseAmount);
    void demote(int demotionAmount);
    void display() const;
    void displayToFile(QTextStream& out) const;

    void setEmployeeNumber(int inEmployeeNumber);
    int getEmployeeNumber() const;

    void setFullName(const QString& inFullName);
    QString getFullName() const;

    void setAge(int inAge);
    int getAge() const;

    void setSex(const QString& inSex);
    QString getSex() const;

    void setAddress(const QString& inAddress);
    QString getAddress() const;

    void setPassportData(int inPassportData);
    int getPassportData() const;

    void setSalary();
    int getSalary() const;

    void setJobCode(int inJobCode);
    int getJobCode() const;

    bool getIsHired() const;

private:
    int mEmployeeNumber;
    QString mFullName;
    int mAge;
    QString mSex;
    QString mAddress;
    int mPassportData;
    int mJobCode;
    bool mIsHired;
    int mSalary;
};

#endif // EMPLOYEE_H
