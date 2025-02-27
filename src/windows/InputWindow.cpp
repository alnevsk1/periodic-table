#include "InputWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <string>
#include <sstream>
#include <iostream>

InputWindow::InputWindow(QWidget* parent) : QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8");
    exitButton = new QPushButton(this);
    addButton = new QPushButton(this);
    discLabel = new QLabel(this);
    posLabel = new QLabel(this);
    nameLabel = new QLabel(this);
    massLabel = new QLabel(this);
    typeLabel = new QLabel (this);
    posEdit = new QLineEdit(this);
    nameEdit = new QLineEdit(this);
    massEdit = new QLineEdit(this);
    typeEdit = new QLineEdit(this);
    errorBox = new QMessageBox(this);
    setWindowTitle(codec->toUnicode("Добавление элементов в таблицу"));


    exitButton -> setText(codec->toUnicode("Выход"));
    addButton -> setText(codec->toUnicode("Добавить элемент"));

    discLabel -> setText(codec->toUnicode("Введите полную информацию о новом элементе и нажмите добавить."));
    posLabel -> setText(codec->toUnicode("Номер элемента"));
    nameLabel -> setText(codec->toUnicode("Имя элемента"));
    massLabel -> setText(codec->toUnicode("Масса элемента"));
    typeLabel -> setText(codec->toUnicode("Тип проводимости элемента"));


    QVBoxLayout* labels = new QVBoxLayout();
    QVBoxLayout* edits = new QVBoxLayout();
    QHBoxLayout* us = new QHBoxLayout();
    QHBoxLayout* buttons = new QHBoxLayout();
    QVBoxLayout* res = new QVBoxLayout(this);

    labels ->addWidget(posLabel);
    labels ->addWidget(nameLabel);
    labels -> addWidget(massLabel);
    labels -> addWidget(typeLabel);

    edits -> addWidget(posEdit);
    edits -> addWidget(nameEdit);
    edits -> addWidget(massEdit);
    edits -> addWidget(typeEdit);

    buttons -> addWidget(addButton);
    buttons -> addWidget(exitButton);

    us -> addLayout(labels);
    us -> addLayout(edits);

    res -> addWidget(discLabel);
    res -> addLayout(us);
    res -> addLayout (buttons);

    connect(exitButton,SIGNAL(clicked()),this,SLOT(exit()));
    connect(addButton,SIGNAL(clicked()),this,SLOT(add()));
}


std::string Formater(std::string input)
{
    while((input.find(" ",0)) != std::string::npos)
    {
        size_t space = input.find(" ");
        input.erase(space,1);
    }
    return input;
}

void InputWindow:: exit()
{
    QWidget::close();
}


std::vector<Element> readElementsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Element> elements;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Element element;
        std::string number, name, weight, classification, trash;
        std::getline(ss,trash,'|');
        std::getline(ss, number, '|');
        std::getline(ss, name, '|');
        std::getline(ss, weight, '|');
        std::getline(ss, classification, '|');

        element.position = number;
        element.name = name;
        element.mass = weight;
        element.type = classification;
        elements.push_back(element);
    }
    file.close();
    return elements;
}


void writeElementsToFile(const std::string& filename, const std::vector<Element>& elements) {
    std::ofstream file(filename);
    for (const auto& element : elements) {
        file << "| " << element.position << " | " << element.name << " | " << element.mass << " | " << element.type << " |\n";
    }
    file.close();
}


void addAndSortElement(const std::string& filename, const std::string number, const std::string& name, const std::string atomicWeight, const std::string& classification) {
    std::vector<Element> elements = readElementsFromFile(filename);
    Element newElement = {number, name, atomicWeight, classification};
    elements.push_back(newElement);
    for (size_t i = 1; i < elements.size(); ++i) {
        Element key = elements[i];
        int j = i - 1;
        while (j >= 0 && std::stoi(elements[j].position) >std::stoi( key.position)) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = key;
    }
    writeElementsToFile(filename, elements);
}

void InputWindow::add()
{
    std::string filename = "../../resources/dataBase.txt";
    if(!(note.is_open()))
        note.open(filename);

    try
    {
        if(posEdit->text().isEmpty() && nameEdit->text().isEmpty()
            && massEdit->text().isEmpty() && typeEdit->text().isEmpty() )
        {
            throw (1);
        }
        std::string pos;
        std::string formatedPos = Formater(posEdit->text().toStdString());
        std::string formatedName = Formater(nameEdit->text().toStdString());
        std::string formatedMass = Formater(massEdit->text().toStdString());
        std::string formatedType = Formater(typeEdit->text().toStdString());

        while(std::getline(note,pos,'\n'))
        {
            if(pos.find(" " + formatedPos + " ") != pos.npos)
                throw(false);
        }


        elements = readElementsFromFile(filename);
        addAndSortElement(filename,formatedPos,formatedName,formatedMass,formatedType);
        errorBox -> setText(codec->toUnicode("Успешно!"));
        errorBox -> show();
        posEdit->clear();
        nameEdit->clear();
        massEdit->clear();
        typeEdit->clear();
        note.close();
    }
    catch(int)
    {
        errorBox -> setText(codec->toUnicode("Заполните все поля!!!"));
        errorBox -> show();
    }
    catch(bool)
    {
        errorBox -> setText(codec->toUnicode("Элемент с таким номером уже существует!!"));
        errorBox -> show();
    }
}














