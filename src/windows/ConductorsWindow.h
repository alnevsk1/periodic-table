#ifndef CONDUCTORSWINDOW_H
#define CONDUCTORSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <fstream>
#include <QTextCodec>
#include <QTableWidget>
#include "../Elements.h"

class ConductorsWindow : public QWidget
{
    Q_OBJECT

public:
    ConductorsWindow (QWidget *parent = nullptr );
    void FillTextP ();
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

#endif // CONDUCTORSWINDOW_H
