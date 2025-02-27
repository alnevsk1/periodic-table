#include "GraphWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <sstream>

GraphWindow::GraphWindow(QWidget* parent) : QWidget(parent)
{
    setFixedSize(800,600);
    graph = new QChartView(this);
    exitButton = new QPushButton(this);
    codec = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codec->toUnicode("График"));

    exitButton -> setText(codec->toUnicode("Выход"));


    QVBoxLayout* main = new QVBoxLayout(this);
    main -> addWidget(graph);
    main -> addWidget(exitButton);

    connect(exitButton,SIGNAL(clicked()),this,SLOT(exit()));

}

void GraphWindow::exit()
{
    QWidget::close();
}

void GraphWindow::SetGraph(std::vector<Element> origin)
{

    QLineSeries *series = new QLineSeries();
    for (const auto& el:origin)
    {
        *series << QPointF(std::stoi(el.position), std::stod(el.mass));
    }

    // Создаём график и добавляем в него синусоиду
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("График зависимости атомной массы элемента от его номера");

    // Настройка осей графика
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("X, позиция");
    axisX->setLabelFormat("%i");
    axisX->setMinorTickCount(1);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Y, а.м.");
    axisY->setLabelFormat("%g");
    axisY->setMinorTickCount(1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    graph->setChart(chart);
}

void GraphWindow::Draw()
{
    std::string line;
    std::vector <Element> everything;
    std::string pos;
    std::string name;
    std::string mass;
    std::string type;
    std::string trash;
    if(true)
    {
        note.open("../../resources/dataBase.txt");
        note.seekg(0);
        while(std::getline(note,line,'\n'))
        {
            std::stringstream in (line);
            std::getline(in,trash,'|');
            std::getline(in,pos,'|');
            std::getline(in,name,'|');
            std::getline(in,mass,'|');
            std::getline(in,type,'|');
            Element news = {pos,name,mass,type};
            everything.push_back(news);
        }
        SetGraph(everything);
        note.close();
        everything.clear();
    }
}
