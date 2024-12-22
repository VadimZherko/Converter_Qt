#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(Convert()));
    QObject::connect(ui->buttonClear,SIGNAL(clicked()),this,SLOT(lineEditClear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Convert()
{
    QString lable_value = ui->lineEdit->text();
    if(lable_value != '0' and lable_value.toDouble() == 0)
    {
        QMessageBox::warning(this,"Error", "Invalid input");
        return;
    }

    double value = ui->lineEdit->text().toDouble();

    if(ui->comboBox_3->currentText() == "length")
    {
        double converted_value = value / lengthValues[ui->comboBox->currentText()];
        converted_value *= lengthValues[ui->comboBox_2->currentText()];
        ui->label->setText(QString::number(converted_value, 'g', 10));
    }
    else if(ui->comboBox_3->currentText() == "time")
    {
        double converted_value = value * timeValues[ui->comboBox->currentText()];
        converted_value /= timeValues[ui->comboBox_2->currentText()];
        ui->label->setText(QString::number(converted_value, 'g', 10));
    }
    else if(ui->comboBox_3->currentText() == "weight")
    {
        double converted_value = value / weightValues[ui->comboBox->currentText()];
        converted_value *= weightValues[ui->comboBox_2->currentText()];
        ui->label->setText(QString::number(converted_value, 'g', 10));
    }
    else QMessageBox::information(this,"Error", "Choose type of value");
}

void MainWindow::lineEditClear()
{
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->label->setText("Converted Value");
}

void MainWindow::on_comboBox_3_activated(int index)
{
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    if(ui->comboBox_3->currentText() == "length")
    {
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        for(auto it = lengthValues.cbegin(); it != lengthValues.cend(); it++)
        {
            ui->comboBox->addItem(it->first);
            ui->comboBox_2->addItem(it->first);
        }
    }
    else if(ui->comboBox_3->currentText() == "time")
    {
        for(auto it = timeValues.cbegin(); it != timeValues.cend(); it++)
        {
            ui->comboBox->addItem(it->first);
            ui->comboBox_2->addItem(it->first);
        }
    }
    else if(ui->comboBox_3->currentText() == "weight")
    {
        for(auto it = weightValues.cbegin(); it != weightValues.cend(); it++)
        {
            ui->comboBox->addItem(it->first);
            ui->comboBox_2->addItem(it->first);
        }
    }
}

