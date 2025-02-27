#ifndef INSULATORSWINDOW_H
#define INSULATORSWINDOW_H
#include <QWidget>
#include <QTextEdit>
#include <QTextCodec>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <fstream>
#include <vector>
#include <Elements.h>
#include <QLineEdit>

class InsulatorsWindow : public QWidget
{
    Q_OBJECT

public:
    InsulatorsWindow (QWidget *parent = nullptr );
    void FillTextI ();
    void AddTable(std::vector <Element>,int size);


protected:
    QStringList list;

    QTableWidgetItem* item;
    QLabel* maxLabel;
    QLineEdit* maxEdit;
    std::fstream note;
    QTableWidget* table;
    QTextCodec* codec;
    QLabel *discLabel;
    QPushButton* findButton;
    QPushButton* exitButton;

public slots:
    void find();
    void exit();
};

#endif // INSULATORSWINDOW
