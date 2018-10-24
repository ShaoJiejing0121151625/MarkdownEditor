#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWebView/QtWebView>
#include <QLabel>
#include<iostream>
#include<fstream>
#include <QProcess>
#include"md2html.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(compilemd()));



    QString currentPath = QDir::currentPath();
    qDebug()<<currentPath <<endl;


    //QFile file("F:\\MarkdownEditor\\build-MarkdownEditor-Desktop_Qt_5_11_2_MSVC2017_64bit-Debug\\debug\\a.html");
    QFile file("F:/MarkdownEditor/build-MarkdownEditor-Desktop_Qt_5_11_2_MSVC2017_64bit-Debug/debug/a.html");
    qDebug()<<currentPath+"/a.html" <<endl;

    //QFile file(currentPath+"/a.html");

    //QFile file("a.html");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    //QTextStream txtInput(&file);
    //QString str;
    QByteArray ba=file.read(file.bytesAvailable());
    QString str=QString(ba);
    file.close();

    //str = QString("<h1><i>Hello</i> <font color = red>Qt!</font></h1><h2>My CSDN blog: <a href=\"https://blog.csdn.net/humanking7\">https://blog.csdn.net/humanking7 </a></h2>");

    ui->label->setText(str);



}
void MainWindow::compilemd()
{

    QString str = ui->textEdit->toPlainText();



    QString currentPath = QDir::currentPath();
    qDebug()<<currentPath <<endl;

    QFile *mdfile = new QFile;
    mdfile->setFileName("a.md");
    if(!mdfile->open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<QObject::tr("打开失败");
    }
    QTextStream *m_stream = new QTextStream(mdfile);
    *m_stream << str << "\r\n";
    m_stream->flush();
    mdfile->close();
    qDebug()<<"Saved"<<endl;

    char input[5] = "a.md";
    char output[7] = "a.html";
    int code_color_scheme = 2;
    //FILE *in_fp, *out_fp;
    //open_file(&in_fp, input);
    //create_file(&out_fp, output);
    FILE *in_fp =fopen(input,"r");
    FILE *out_fp = fopen(output,"w");
    mdparser(out_fp, in_fp, code_color_scheme);

    close_files(&in_fp, &out_fp);

    //Compileit();

    /*
    QProcess process;
    process.execute("mdparser.exe");

    qDebug()<<"Compiling Md"<<endl;
    */
}

MainWindow::~MainWindow()
{

    delete ui;
}
