#include "InsulatorsWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <sstream>

InsulatorsWindow::InsulatorsWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800,600);
    setlocale(LC_CTYPE,"rus");
    codec = QTextCodec::codecForName("UTF-8");
    discLabel = new QLabel(this);
    exitButton = new QPushButton(this);
    findButton = new QPushButton(this);
    table = new QTableWidget(this);
    maxLabel = new QLabel(this);
    maxEdit = new QLineEdit(this);
    setWindowTitle(codec->toUnicode("Поиск определенных изоляторов"));

    maxLabel -> setText(codec->toUnicode("Введите максимальную атомную массу изолятора -->"));

    list << codec->toUnicode("Номер элемента") << codec->toUnicode("Название элемента")
           << codec->toUnicode("Атомная масса") << codec->toUnicode("Тип проводимости") ;

    discLabel -> setText(codec->toUnicode("Найденные изоляторы: "));
    exitButton -> setText(codec->toUnicode("Выход"));
    findButton -> setText(codec->toUnicode("Найти"));
    table->setHorizontalHeaderLabels(list);
    table ->setColumnCount(4);
    table->setColumnWidth(0, 150);
    table->setColumnWidth(1, 150);
    table->setColumnWidth(2, 150);
    table->setColumnWidth(3, 150);

    QHBoxLayout* edit = new QHBoxLayout();
    edit->addWidget(maxLabel);
    edit->addWidget(maxEdit);
    edit->addWidget(findButton);

    QVBoxLayout* result = new QVBoxLayout(this);
    result -> addWidget(discLabel);
    result -> addWidget(table);
    result-> addLayout(edit);
    result -> addWidget(exitButton);

    connect(findButton,SIGNAL(clicked()),this,SLOT(find()));
    connect(maxEdit, SIGNAL(returnPressed()),this, SLOT(find()));
    connect(exitButton,SIGNAL(clicked()),this,SLOT(exit()));
}


void InsulatorsWindow::AddTable(std::vector<Element> origin,int size)
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

std::string removeSpaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void InsulatorsWindow::FillTextI()
{
    table ->setRowCount(0);
    std::string line;
    int counter = 0;
    float del = 0.0001;
    std::vector <Element> everything;
    std::string pos;
    std::string name;
    std::string mass;
    std::string type;
    std::string trash;
    std::string lim;
    if(maxEdit->text().isEmpty())
    {
        lim = "10000";
    }
    else lim = maxEdit->text().toStdString();
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
            removeSpaces(mass);
            removeSpaces(lim);
            if (type.find("золятор")!= std::string::npos &&
                (std::stof(mass) - std::stof(lim)) <= del)
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

void InsulatorsWindow::find()
{
    FillTextI();
}

void InsulatorsWindow::exit()
{
    QWidget::close();
}
