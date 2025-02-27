#include "MainMenu.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>


MainMenu::MainMenu(QWidget *parent): QWidget(parent)
{
    setFixedSize(500, 300);
    codec = QTextCodec::codecForName("UTF-8");
    showcondButton = new QPushButton(this);
    delButton = new QPushButton(this);
    inputButton = new QPushButton(this);
    showsemicondButton =  new QPushButton(this);
    exitButton = new QPushButton(this);
    graphButton = new QPushButton(this);
    showinsulButton = new QPushButton(this);
    viewButton = new QPushButton(this);
    nameLabel = new QLabel(this);

    setWindowTitle(codec->toUnicode("Таблица Менделеева"));

    nameLabel ->setText(codec->toUnicode("Программа 'Работа с таблицей Менделеева'"));
    viewButton -> setText(codec->toUnicode("Вывести все элементы"));
    showcondButton -> setText(codec->toUnicode("Вывести проводники в порядке возврастания их номера"));
    delButton -> setText(codec->toUnicode("Удалить элементы"));
    inputButton -> setText(codec->toUnicode("Добавить элементы"));
    exitButton -> setText(codec->toUnicode("Завершение работы"));
    graphButton -> setText(codec->toUnicode("Построить график зависимости атомной массы элемента от его номера"));
    showinsulButton -> setText(codec->toUnicode("Найти изоляторы до определенной массы"));
    showsemicondButton -> setText(codec->toUnicode("Вывести всю информацию о полупроводниках"));

    QHBoxLayout* iobuttons = new QHBoxLayout();
    iobuttons -> addWidget (inputButton);
    iobuttons -> addWidget (delButton);

    QVBoxLayout* buttons = new QVBoxLayout();
    buttons ->addLayout(iobuttons);
    buttons -> addWidget(viewButton);
    buttons -> addWidget(showcondButton);
    buttons -> addWidget(showinsulButton);
    buttons -> addWidget(showsemicondButton);
    buttons -> addWidget(graphButton);
    buttons -> addWidget(exitButton);

    QVBoxLayout* labels = new QVBoxLayout();
    labels -> addWidget(nameLabel);


    QVBoxLayout* window = new QVBoxLayout(this);
    window -> addLayout(labels);
    window -> addLayout(buttons);

    connect(showsemicondButton, SIGNAL(clicked()), this, SLOT(showSemiCond()));
    connect(delButton, SIGNAL(clicked()), this, SLOT(deleter()));
    connect(inputButton, SIGNAL(clicked()), this, SLOT(input()));
    connect(showcondButton, SIGNAL(clicked()), this, SLOT(showCond()));
    connect(showinsulButton, SIGNAL(clicked()), this, SLOT(showInsul()));
    connect(graphButton, SIGNAL(clicked()), this, SLOT(showGraph()));
    connect(viewButton, SIGNAL(clicked()), this, SLOT(showTable()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(exit()));


}

void MainMenu::deleter()
{
    deleteWindow.show();
}

void MainMenu::showCond()
{
    condWindow.FillTextP();
    condWindow.show();
}

void MainMenu::showSemiCond()
{
    semicondWindow.FillTextPP();
    semicondWindow.show();
}

void MainMenu::input()
{
    inputWindow.show();
}

void MainMenu::showInsul()
{
    insulWindow.FillTextI();
    insulWindow.show();
}

void MainMenu::showGraph()
{
    graphWindow.Draw();
    graphWindow.show();
}

void MainMenu::showTable()
{
    viewWindow.FillText();
    viewWindow.show();
}

void MainMenu::exit()
{
    insulWindow.exit();
    inputWindow.exit();
    graphWindow.exit();
    deleteWindow.exit();
    condWindow.exit();
    semicondWindow.exit();
    viewWindow.exit();
    QWidget::close();

}
