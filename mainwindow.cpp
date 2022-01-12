#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->one,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->two,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->three,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->four,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->five,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->six,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->seven,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->eight,SIGNAL(clicked()),this,SLOT (digits_numbers()));
    connect(ui->nine,SIGNAL(clicked()),this,SLOT (digits_numbers()));


   connect(ui->znack,SIGNAL(clicked()),this,SLOT (operations()));
   connect(ui->proz,SIGNAL(clicked()),this,SLOT (operations()));


    connect(ui->plus,SIGNAL(clicked()),this,SLOT (math_operations()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT (math_operations()));
    connect(ui->delenie,SIGNAL(clicked()),this,SLOT (math_operations()));
    connect(ui->umn,SIGNAL(clicked()),this,SLOT (math_operations()));

        ui->plus->setCheckable(true);
        ui->minus->setCheckable(true);
        ui->delenie->setCheckable(true);
        ui->umn->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
QPushButton *button = (QPushButton *)sender();
double numbers;
QString new_label;

if(ui->label->text().contains(".") && button->text() == "0")
{

   new_label = (ui->label ->text()) + (button->text());

} else{

numbers = (ui->label ->text()+button->text()).toDouble();

 new_label = QString::number(numbers, 'g',12);

}
ui->label->setText(new_label);
}

void MainWindow::on_dv_clicked()
{
 if (!ui->label->text().contains('.'))
    ui->label->setText(ui->label->text()+".");

}



void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double numbers_1;
    QString new_label;

        if(button->text() == "+/-"){
            numbers_1 = (ui->label->text()).toDouble();
            numbers_1 = numbers_1 * -1;
             new_label = QString::number(numbers_1, 'g',12);

             ui->label->setText(new_label);
}else if(button->text() == "%"){
            numbers_1 = (ui->label->text()).toDouble();
            numbers_1 = numbers_1 * 0.01;
             new_label = QString::number(numbers_1, 'g',12);

             ui->label->setText(new_label);
}

}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = (ui->label->text()).toDouble();
    ui->label->setText("");
    button->setChecked(true);

}

void MainWindow::on_ravno_clicked()
{
    double labelnumber, num_second;
    QString new_label;

    num_second =( ui->label-> text()).toDouble();

    if(ui ->plus->isChecked()){
        labelnumber = num_first+num_second;
        new_label = QString::number(labelnumber, 'g',12);
        ui->label->setText(new_label);
        ui ->plus->setChecked(false);

    }else if(ui ->minus->isChecked()){

        labelnumber = num_first-num_second;
        new_label = QString::number(labelnumber, 'g',12);
        ui->label->setText(new_label);
        ui ->minus->setChecked(false);

    }else if(ui ->delenie->isChecked()){

        if(num_second == 0){
          ui->label->setText("0");
        }else{
        labelnumber = num_first/num_second;
        new_label = QString::number(labelnumber, 'g',12);
        ui->label->setText(new_label);
        }
        ui ->delenie->setChecked(false);


    }else if(ui ->umn->isChecked()){

        labelnumber = num_first*num_second;
        new_label = QString::number(labelnumber, 'g',12);
        ui->label->setText(new_label);
        ui ->umn->setChecked(false);
}
}

void MainWindow::on_del_clicked()
{
       ui ->plus->setChecked(false);
       ui ->minus->setChecked(false);
       ui ->delenie->setChecked(false);
       ui ->umn->setChecked(false);
       ui->label->setText("0");

}

void MainWindow::on_pushButton_clicked()
{
   QApplication::quit();
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox:: about(this,"Справка", "Сведения о программе");
}
