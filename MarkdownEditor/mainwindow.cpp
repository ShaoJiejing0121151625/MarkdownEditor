#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setHtml("<font size='35'>h1</font><br><font size='5'>h3</font>");
}

MainWindow::~MainWindow()
{
    delete ui;
}
