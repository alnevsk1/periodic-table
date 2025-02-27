#include "ConductorsWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <sstream>

ConductorsWindow::ConductorsWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800,600);
    setlocale(LC_CTYPE,"rus");
    codec = QTextCodec::codecForName("UTF-8");
    discLabel = new QLabel(this);
    exitButton = new QPushButton(this);
    table = new QTableWidget(this);
    setWindowTitle(codec->toUnicode("Все проводники"));
    list << codec->toUnicode("Номер элемента") << codec->toUnicode("Название элемента")
         << codec->toUnicode("Атомная масса") << codec->toUnicode("Тип проводимости") ;

    discLabel -> setText(codec->toUnicode("Все проводники: "));
    exitButton -> setText(codec->toUnicode("Выход"));
    table->setHorizontalHeaderLabels(list);
    table ->setColumnCount(4);
    table->setColumnWidth(0, 150);
    table->setColumnWidth(1, 150);
    table->setColumnWidth(2, 150);
    table->setColumnWidth(3, 150);

    QVBoxLayout* result = new QVBoxLayout(this);
    result -> addWidget(discLabel);
    result -> addWidget(table);
    result -> addWidget(exitButton);


    connect(exitButton,SIGNAL(clicked()),this,SLOT(exit()));
}

void ConductorsWindow::AddTable(std::vector<Element> origin,int size)
{
    table->setHorizontalHeaderLabels(list);
    int i =0;
    table -> setRowCount(size);
    for (const auto& element: origin)
    {

        item=new QTableWidgetItem();
        item->setFlags(Qt::NoItemFlags);
        item->setText(QString::fromStdString(element.position));
        table->setItem(i,0,item);
        item=new QTableWidgetItem();
        item->setFlags(Qt::NoItemFlags);
        item->setText(QString::fromStdString(element.name));
        table->setItem(i,1,item);
        item=new QTableWidgetItem();
        item->setFlags(Qt::NoItemFlags);
        item->setText(QString::fromStdString(element.mass));
        table->setItem(i,2,item);
        item=new QTableWidgetItem();
        item->setFlags(Qt::NoItemFlags);
        item->setText(QString::fromStdString(element.type));
        table->setItem(i,3,item);
        i++;
    }
}

void ConductorsWindow::FillTextP()
{
    table ->setRowCount(0);
    std::string line;
    int counter = 0;
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
            if (type.find("Проводник")!= std::string::npos)
            {
                Element news = {pos,name,mass,type};
                everything.push_back(news);
                counter ++;
            }
        }

        AddTable(everything,counter);
        note.close();
        everything.clear();
    }
}

void ConductorsWindow::exit()
{
    QWidget::close();
}
