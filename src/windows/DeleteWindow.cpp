#include "DeleteWindow.h"
#include <QVBoxLayout>
#include <sstream>
#include <QHBoxLayout>
#include <fstream>

DeleteWindow::DeleteWindow(QWidget *parent) : QWidget(parent)
{
    setlocale(LC_CTYPE,"rus");
    codec = QTextCodec::codecForName("UTF-8");
    exitButton = new QPushButton (this);
    deleteButton = new QPushButton(this);
    discLabel = new QLabel(this);
    nameLabel = new QLabel(this);
    nameEdit = new QLineEdit(this);
    msgError = new QMessageBox(this);
    msgSuccess = new QMessageBox(this);
    setWindowTitle(codec->toUnicode("Удаление элементов из таблицы"));


    exitButton -> setText(codec->toUnicode("Выход"));
    deleteButton -> setText(codec->toUnicode("Удалить"));
    discLabel -> setText(codec->toUnicode("Введите название элемента, который хотите удалить, и нажмите 'Удалить'"));
    nameLabel -> setText(codec->toUnicode("Название: "));
    msgSuccess -> setText(codec->toUnicode("Успешно"));



    QHBoxLayout* name = new QHBoxLayout();
    name -> addWidget(nameLabel);
    name -> addWidget(nameEdit);

    QHBoxLayout* buttons = new QHBoxLayout();
    buttons -> addWidget (deleteButton);
    buttons -> addWidget(exitButton);



    QVBoxLayout* result = new QVBoxLayout(this);
    result -> addWidget(discLabel);
    result -> addLayout(name);
    result -> addLayout(buttons);


    connect (deleteButton,SIGNAL(clicked()),this,SLOT(deleter()));
    connect (exitButton,SIGNAL(clicked()),this,SLOT(exit()));
}


void DeleteWindow::exit()
{
    QWidget::close();
}


std::vector<Element> DeleteWindow::Del(std::string fname, std::vector <Element> everything)
{
    std::vector <Element> regular;
    for ( auto& element: everything)
    {

        std::string formname = removeSpaces(element.name);

        if ( (!(formname == fname)))
        {
            regular.push_back((element));
        }
    }
    return regular;
}


std::string DeleteWindow::removeSpaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void DeleteWindow::deleter()
{
    const std::string filename = "../../resources/dataBase.txt";

    std::string line;
    std::vector <Element> everything;
    std::string pos;
    std::string name;
    std::string mass;
    std::string type;
    std::string trash;

    std::ifstream fin(filename);

    while(std::getline(fin,line,'\n'))
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

    fin.close();

    std::vector <Element> founded;
    std::string entered_name;
    entered_name = nameEdit ->text().toStdString();
    removeSpaces(entered_name);

    std::ofstream fout (filename);
    try
    {
        bool key = true;
        if (entered_name.empty())
        {
            throw(1);
        }



        founded = Del(entered_name,everything);
        for( const auto& el: founded)
        {
            fout << "| " << el.position << "| " << el.name << "| " << el.mass << "| " << el.type << "| " << std::endl;
        }
        fout.close();


        for( auto& el:everything)
        {
            removeSpaces(el.name);
            if (el.name == entered_name)
                key = false;

        }
        if(key)
        {
            throw (key);
        }
        nameEdit->clear();
        msgSuccess->open();
    }
    catch(bool)
    {
        msgError -> setText(codec->toUnicode("Такого элемента нет!"));
        msgError -> show();
    }

    catch(int)
    {
        msgError -> setText(codec->toUnicode("Введите поле!!!"));
        msgError -> show();
    }



}
