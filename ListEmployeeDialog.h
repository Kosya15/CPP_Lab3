#ifndef LISTEMPLOYEEDIALOG_H
#define LISTEMPLOYEEDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>

class ListEmployeeDialog : public QDialog {
    Q_OBJECT

public:
    ListEmployeeDialog(QWidget *parent = nullptr);

private slots:
    void loadData();

private:
    QTextEdit *textEdit;
    QPushButton *loadButton;
};


#endif // LISTEMPLOYEEDIALOG_H
