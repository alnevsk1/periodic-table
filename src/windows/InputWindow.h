#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H
#include <QWidget>
#include <QValidator>
#include <QPushButton>
#include <QLabel>
#include <QTextCodec>
#include <QLineEdit>
#include "Elements.h"
#include <QMessageBox>
#include <fstream>

class InputWindow : public QWidget
{
    Q_OBJECT

public:
    InputWindow(QWidget* parent = nullptr);
protected:
    std::fstream note;
    QMessageBox* errorBox;
    std::vector<Element> elements;
    QPushButton* exitButton;
    QTextCodec* codec;
    QPushButton* addButton;
    QLabel* discLabel;
    QLabel* posLabel;
    QLabel* nameLabel;
    QLabel* massLabel;
    QLabel* typeLabel;
    QLineEdit* posEdit;
    QLineEdit* nameEdit;
    QLineEdit* massEdit;
    QLineEdit* typeEdit;

public slots:
    void exit();
    void add();

};

#endif // INPUTWINDOW_H
