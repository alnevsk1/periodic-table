#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextCodec>
#include "SemiconductorsWindow.h"
#include "DeleteWindow.h"
#include <Elements.h>
#include "InputWindow.h"
#include "ConductorsWindow.h"
#include "InsulatorsWindow.h"
#include "GraphWindow.h"
#include "TableView.h"

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);

protected:
    InsulatorsWindow insulWindow;
    SemiconductorsWindow semicondWindow;
    DeleteWindow deleteWindow;
    ConductorsWindow condWindow;
    InputWindow inputWindow;
    GraphWindow graphWindow;
    TableView viewWindow;

    QTextCodec* codec;
    QPushButton* delButton;
    QPushButton* showcondButton;
    QPushButton* showsemicondButton;
    QPushButton* exitButton;
    QPushButton* graphButton;
    QPushButton* showinsulButton;
    QPushButton* inputButton;
    QPushButton* viewButton;
    QLabel* nameLabel;

public slots:

    void showSemiCond();

    void deleter();

    void input();

    void showCond();

    void showInsul();

    void showGraph();

    void showTable();

    void exit();

};
#endif // MAINMENU_H
