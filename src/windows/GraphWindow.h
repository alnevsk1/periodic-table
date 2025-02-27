#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H
#include <QWidget>
#include <QPushButton>
#include <QChart>
#include <QTextCodec>
#include <fstream>
#include <Elements.h>
#include <QChartView>
class GraphWindow : public QWidget
{
    Q_OBJECT

public:
    GraphWindow(QWidget *parent = nullptr);
    void Draw();
    void SetGraph(std::vector<Element> origin);
protected:
    std::fstream note;
    QChartView* graph;
    QTextCodec* codec;
    QPushButton* exitButton;

public slots:
    void exit();

};

#endif // GRAPHWINDOW_H
