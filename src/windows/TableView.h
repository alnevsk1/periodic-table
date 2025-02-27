#ifndef TableVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include <QTextEdit>
#include <QTextCodec>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <fstream>
#include <vector>
#include <Elements.h>

class TableView : public QWidget
{
    Q_OBJECT

public:
    TableView (QWidget *parent = nullptr );
    void FillText ();
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
#endif // VIEW_H
