#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QWidget>
#include <vector>
#include <QTextCodec>
#include "../Elements.h"
#include <QMessageBox>

class DeleteWindow : public QWidget
{
    Q_OBJECT
public:
    DeleteWindow (QWidget *parent = nullptr);
    std::vector <Element> Del(std::string fname, std::vector <Element> everything);
    std::string removeSpaces(std::string &str);

protected:
    QLineEdit* nameEdit;
    QMessageBox* msgSuccess;
    QMessageBox* msgError;
    QLabel* discLabel;
    QLabel* nameLabel;
    QPushButton* deleteButton;
    QPushButton* exitButton;

    QTextCodec* codec;

public slots:
    void exit();
    void deleter();

};

#endif // DELETEWINDOW_H
