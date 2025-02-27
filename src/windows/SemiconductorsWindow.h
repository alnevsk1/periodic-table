#ifndef SEMICONDUCTORSWINDOW_H
#define SEMICONDUCTORSWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QTextCodec>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <fstream>
#include <vector>
#include <Elements.h>


class SemiconductorsWindow : public QWidget
{
    Q_OBJECT

public:
    SemiconductorsWindow (QWidget *parent = nullptr );
    void FillTextPP ();
    void AddTable(std::vector <Element>,int size);


protected:
    QStringList list;

    QTableWidgetItem* item;
    std::fstream note;
    QTableWidget* table;
    QTextCodec* codec;
    QLabel *discLabel;
    QPushButton* exitButton;

public slots:
    void exit();

};

#endif // SEMICONDUCTORSWINDOW_H
