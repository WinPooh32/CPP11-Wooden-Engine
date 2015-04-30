#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_map1_clicked()
{
    if(ui->map1->text() == "black")
    {
        ui->map1->setText("blue");
    }
    else if(ui->map1->text() == "blue")
    {
        ui->map1->setText("green");
    }
    else if(ui->map1->text() == "greem")
    {
        ui->map1->setText("red");
    }
    else if(ui->map1->text() == "red")
    {
        ui->map1->setText("black");
    }
}

void MainWindow::on_map2_clicked()
{
    if(ui->map2->text() == "none")
    {
        ui->map2->setText("land");
    }
    else if(ui->map2->text() == "land")
    {
        ui->map2->setText("water");
    }
    else if(ui->map2->text() == "water")
    {
        ui->map2->setText("fire");
    }
    else if(ui->map2->text() == "fire")
    {
        ui->map2->setText("none");
    }
}


void MainWindow::on_map3_clicked()
{
    if(ui->map3->text() == "none")
    {
        ui->map3->setText("land");
    }
    else if(ui->map3->text() == "land")
    {
        ui->map3->setText("water");
    }
    else if(ui->map3->text() == "water")
    {
        ui->map3->setText("fire");
    }
    else if(ui->map3->text() == "fire")
    {
        ui->map3->setText("none");
    }
}
void MainWindow::on_map4_clicked()
{
    if(ui->map4->text() == "none")
    {
        ui->map4->setText("land");
    }
    else if(ui->map4->text() == "land")
    {
        ui->map3->setText("water");
    }
    else if(ui->map3->text() == "water")
    {
        ui->map3->setText("fire");
    }
    else if(ui->map3->text() == "fire")
    {
        ui->map3->setText("none");
    }
}








