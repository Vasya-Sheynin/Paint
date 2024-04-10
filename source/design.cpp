#include "design.h"
#include "ui_design.h"
#include "rect.h"
#include "circle.h"
#include <typeinfo>

Design::Design(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Design)
{
    ui->setupUi(this);

    this->setFixedSize(700, 500);
    ui->colorWidget->setFixedSize(ui->colorButton->height()*2, ui->colorButton->height()*2);
    ui->colorWidget->setStyleSheet("border: 1px solid black; background-color: white");

    QRegExp regexWid("^(\\d{3})$");
    QRegExp regexLen("^[0-8]\\d{2}$");
    QRegExp regexR("^(\\d{2})$");

    QValidator *valWid = new QRegExpValidator(regexWid);
    QValidator *valLen = new QRegExpValidator(regexLen);
    QValidator *valR = new QRegExpValidator(regexR);
    ui->lenInput->setValidator(valLen);
    ui->widthInput->setValidator(valWid);
    ui->radiusInput->setValidator(valR);

    ui->lenInput->setEnabled(false);
    ui->widthInput->setEnabled(false);
    ui->radiusInput->setEnabled(false);

    connect(ui->colorButton, &QPushButton::clicked, this, [&](){
        QColorDialog *colorDialog = new QColorDialog;
        color = colorDialog->getColor();
        ui->colorWidget->setStyleSheet("border: 1px solid black; background-color: "+color.name()); delete colorDialog;});

    connect(ui->applyBtn, &QPushButton::clicked, this, [&](){
        lineStyle = penStyleFromString(ui->comboBox->currentText());
        fig->setItemPen(QPen(color, ui->spinBox->text().toInt(), lineStyle));
        if(dynamic_cast<Rect*>(fig))
            dynamic_cast<Rect*>(fig)->setSize(ui->lenInput->text().toInt(), ui->widthInput->text().toInt());
        if(dynamic_cast<Circle*>(fig))
            dynamic_cast<Circle*>(fig)->setR(ui->radiusInput->text().toInt());
        this->close();});
}

Design::~Design()
{
    delete ui;
}

Qt::PenStyle Design::penStyleFromString(QString str)
{
if(str == "Solid line")
    return Qt::SolidLine;
if(str == "Dash line")
    return Qt::DashLine;
if(str == "Dash-Dot line")
    return Qt::DashDotLine;
if(str == "Dash-Dot-Dot line")
    return Qt::DashDotDotLine;
if(str == "Dot line")
    return Qt::DotLine;
}

void Design::setItem(Figure* f)
{
    fig = f;
    if(dynamic_cast<Rect*>(fig))
    {
        ui->lenInput->setEnabled(true);
        ui->lenInput->setText(QString::number(dynamic_cast<Rect*>(fig)->getSize().width()));
        ui->widthInput->setEnabled(true);
        ui->widthInput->setText(QString::number(dynamic_cast<Rect*>(fig)->getSize().height()));
    }
    else if(dynamic_cast<Circle*>(fig))
    {
        ui->radiusInput->setEnabled(true);
        ui->radiusInput->setText(QString::number(dynamic_cast<Circle*>(fig)->getR()));
    }
}
