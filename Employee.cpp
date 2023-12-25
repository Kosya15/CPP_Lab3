#include "Employee.h"
#include <QDebug>

Employee::Employee() {
    mEmployeeNumber = -1;
    mFullName = "";
    mAge = 0;
    mSex = "";
    mAddress = "";
    mPassportData = 0;
    mJobCode = 0;
    mIsHired = false;
    mSalary = 0;
}

void Employee::hire() {
    mIsHired = true;
}

void Employee::fire() {
    mIsHired = false;
}

void Employee::promote(int raiseAmount) {
    if (mIsHired) {
        mSalary += raiseAmount;
        qDebug() << "Employee promoted! New salary for " << getFullName() << ": $" << mSalary;
    } else {
        qDebug() << "Cannot promote! Employee " << getFullName() << " is not currently hired.";
    }
}

void Employee::demote(int demotionAmount) {
    if (mIsHired) {
        mSalary -= demotionAmount;
        qDebug() << "Employee demoted! New salary for " << getFullName() << ": $" << mSalary;
    } else {
        qDebug() << "Cannot demote. Employee " << getFullName() << " is not currently hired.";
    }
}

void Employee::display() const {
    qDebug() << "-------------------------";
    qDebug() << "Employee Number: " << getEmployeeNumber();
    qDebug() << "Employee: " << getFullName();
    qDebug() << "Age: " << getAge();
    qDebug() << "Sex: " << getSex();
    qDebug() << "Address: " << getAddress();
    qDebug() << "Passport data: " << getPassportData();
    qDebug() << "Job code: " << getJobCode();
    qDebug() << "Salary: $" << getSalary();
    qDebug() << (mIsHired ? "Current Employee" : "Former Employee");
    qDebug() << "-------------------------";
}

// В класі Employee
void Employee::displayToFile(QTextStream& out) const {
    out << "-------------------------" << Qt::endl;
    out << "Employee Number: " << getEmployeeNumber() << Qt::endl;
    out << "Employee: " << getFullName() << Qt::endl;
    out << "Age: " << getAge() << Qt::endl;
    out << "Sex: " << getSex() << Qt::endl;
    out << "Address: " << getAddress() << Qt::endl;
    out << "Passport data: " << getPassportData() << Qt::endl;
    out << "Job code: " << getJobCode() << Qt::endl;
    out << "Salary: $" << getSalary() << Qt::endl;
    out << (mIsHired ? "Current Employee" : "Former Employee") << Qt::endl;
    out << "-------------------------" << Qt::endl;
}



// -----------------------------------Accessors and getters


// ---------------------------------Employee Number
void Employee::setEmployeeNumber(int inEmployeeNumber) {
    mEmployeeNumber = inEmployeeNumber;
}

int Employee::getEmployeeNumber() const {
    return mEmployeeNumber;
}


// -----------------------------------Full Name
void Employee::setFullName(const QString& inFullName) {
    mFullName = inFullName;
}
QString Employee::getFullName() const {
    return mFullName;
}

// ----------------------------------Age
void Employee::setAge(int inAge) {
    mAge = inAge;
}

int Employee::getAge() const {
    return mAge;
}

// --------------------------------Sex
void Employee::setSex(const QString& inSex){
    mSex = inSex;
}

QString Employee::getSex() const {
    return mSex;
}

// -----------------------------------------Address
void Employee::setAddress(const QString& inAddress){
    switch (mPassportData) {
    case 1001:
        mAddress = "Kyiv, ";
        break;
    case 1002:
        mAddress = "Kharkiv, ";
        break;
    case 1003:
        mAddress = "Odesa, ";
        break;
    case 1004:
        mAddress = "Dnipro, ";
        break;
    case 1005:
        mAddress = "Donetsk, ";
        break;
    case 1006:
        mAddress = "Zaporizhzhia, ";
        break;
    case 1007:
        mAddress = "Lviv, ";
        break;
    case 1008:
        mAddress = "Kryvyi Rih, ";
        break;
    case 1009:
        mAddress = "Mykolayiv, ";
        break;
    case 1010:
        mAddress = "Sevastopol, ";
        break;
    default:
        mAddress = "Unknown city, ";
        break;
    }
    mAddress += inAddress;
}

QString Employee::getAddress() const {
    return mAddress;
}

// -------------------------------Passport data
void Employee::setPassportData(int inPassportData) {
    mPassportData = inPassportData;
}

int Employee::getPassportData() const {
    return mPassportData;
}

// -----------------------------------Job code
void Employee::setJobCode(int inJobCode) {
    mJobCode = inJobCode;
}

int Employee::getJobCode() const {
    return mJobCode;
}

// --------------------------------------Salary
void Employee::setSalary(){
    switch (mJobCode) {
    case 1:
        mSalary = 235;
        break;
    case 2:
        mSalary = 250;
        break;
    case 3:
        mSalary = 260;
        break;
    case 4:
        mSalary = 300;
        break;
    case 5:
        mSalary = 400;
        break;
    case 6:
        mSalary = 500;
        break;
    default:
        qDebug() << "Unknown job code!";
        break;
    }
}

int Employee::getSalary() const {
    return mSalary;
}



// ---------------------Hired---------------
bool Employee::getIsHired() const {
    return mIsHired;
}
