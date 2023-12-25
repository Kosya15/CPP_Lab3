// database.h
#ifndef DATABASE_H
#define DATABASE_H

#include "Employee.h"
#include <QTextStream>

const int kMaxEmployees = 10;
const int kFirstEmployeeNumber = 1;

class Database {
public:
    Database();
    ~Database();
    Employee& addEmployee(const QString& inFullName, int inAge, const QString& inSex, const QString& inAddress, int inPassportData, int inJobCode);
    Employee& getEmployee(int inEmployeeNumber);
    void displayAll();
    void displayCurrent();
    void displayFormer();
    void displayInfo();

    void saveToFile(const QString &filename);
    void displayAllToFile(QTextStream& out);
    void loadFromFile(const QString &filename);

protected:
    Employee mEmployees[kMaxEmployees];
    int mNextSlot;
    int mNextEmployeeNumber;
};

#endif // DATABASE_H
