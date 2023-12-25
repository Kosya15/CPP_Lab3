// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include "database.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createButtons();
    Database mDatabase;

private slots:
    void hireEmployee();
    void fireEmployee();
    void promoteEmployee();
    void demoteEmployee();
    void listAllEmployees();

    void saveData();
private:
    QPushButton *hireButton;
    QPushButton *fireButton;
    QPushButton *promoteButton;
    QPushButton *demoteButton;
    QPushButton *listAllButton;
    QPushButton *saveButton;
};
#endif // MAINWINDOW_H
