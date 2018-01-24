#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(Filter()));
    connect(ui->checkBox_2, SIGNAL(clicked(bool)), this, SLOT(Filter()));
    connect(ui->checkBox_3, SIGNAL(clicked(bool)), this, SLOT(Filter()));
    connect(ui->checkBox_4, SIGNAL(clicked(bool)), this, SLOT(Filter()));
    connect(ui->checkBox_5, SIGNAL(clicked(bool)), this, SLOT(Filter()));
    connect(ui->checkBox_6, SIGNAL(clicked(bool)), this, SLOT(Filter()));
    connect(ui -> pushButton, SIGNAL(clicked(bool)), this, SLOT(PacOut()));

    connect(ui -> pushButton_2, SIGNAL(clicked(bool)), this, SLOT(GroupTime()));
    connect(ui -> pushButton_3, SIGNAL(clicked(bool)), this, SLOT(GroupRunning()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::PacOut()
{
    ui->listWidget->clear();
    QFile file("E:\\Users\\Exam\\Exam\\pacman.log");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream input(&file);
        QString str;
        while (!input.atEnd())
        {
            str = input.readLine();
            if (str.contains("[PACMAN]"))
            {
                ui->listWidget->addItem(str.remove("[PACMAN]"));
            }
        }
    }
    file.close();
}
void MainWindow::Filter()
{
    if (ui->checkBox->isChecked())
    {
        Check=4;
    }
    if (ui->checkBox_2->isChecked())
    {
        Check=5;
    }
    if (ui->checkBox_3->isChecked())
    {
        Check=6;
    }
    if (ui->checkBox_4->isChecked())
    {
        Check=3;
    }
    if (ui->checkBox_5->isChecked())
    {
        Check=2;
    }
    if (ui->checkBox_6->isChecked())
    {
        Check=1;
    }
    ui->listWidget->clear();
    QFile file("E:\\Users\\Exam\\Exam\\pacman.log");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream input(&file);
        QString str;
        while (!input.atEnd())
        {
            str = input.readLine();
            if (!str.contains("[ALPM-SCRIPTLET]"))
            {
                switch (Check)
                {
                case 1:
                {
                    if (str.contains("installed"))
                    {
                        ui->listWidget->addItem( str.remove("[PACMAN]"));
                    }
                    break;
                }
                case 2:
                {
                    if (str.contains("reinstalled"))
                    {
                        ui->listWidget->addItem( str.remove("[PACMAN]"));
                    }
                    break;
                }
                case 3:
                {
                    if (str.contains("upgraded"))
                    {
                        ui->listWidget->addItem( str.remove("[PACMAN]"));
                    }
                    break;
                }
                case 4:
                {
                    if (str.contains("removed"))
                    {
                        ui->listWidget->addItem( str.remove("[PACMAN]"));
                    }
                    break;
                }
                case 5:
                {
                    if (str.contains("synchronizing"))
                    {
                        ui->listWidget->addItem( str.remove("[PACMAN]"));
                    }
                    break;
                }
                case 6:
                {
                    if (str.contains("starting"))
                    {
                        ui->listWidget->addItem( str.remove("[PACMAN]"));
                    }
                    break;
                }
                }
                }
            }
     }
    file.close();
}
void MainWindow::GroupRunning()
{
    ui->listWidget->clear();
    QString T;
    T=ui->lineEdit->text();
    int T1=T.toInt();
    T=ui->lineEdit_2->text();
    int T2=T.toInt();
    bool f = true;
    QFile file("E:\\Users\\Exam\\Exam\\pacman.log");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream input(&file);
        QString str;
        int count=0;
        while (!input.atEnd() && f)
        {
            str = input.readLine();
            if (str.contains("Running") & !str.contains("[ALPM-SCRIPTLET]"))
            {
                count++;
            }
            if ((count>=T1) & (count<T2) & !str.contains("[ALPM-SCRIPTLET]"))
            {
                ui->listWidget->addItem(str.remove("[PACMAN]"));
            }
            if (count==T2)
            {
                ui->listWidget->addItem(str.remove("[PACMAN]"));
                f = false;
            }
        }
    }
    file.close();
}

void MainWindow::GroupTime()
{
    ui->listWidget->clear();
    QString T1,T2;

    T1=ui->lineEdit_3->text();
    T2=ui->lineEdit_5->text();
    QString F1 = "["+T1+" "+T2+"]";
    T1=ui->lineEdit_4->text();
    T2=ui->lineEdit_6->text();
    QString F2 = "["+T1+" "+T2+"]";

    bool f = true;
    QFile file("E:\\Users\\Exam\\Exam\\pacman.log");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream input(&file);
        QString str;
        int count=0;
        while (!input.atEnd() && f)
        {
            str = input.readLine();
            if (str.contains(F1))
            {
                count=1;
            }
            if(count>0 && !str.contains(F2))
            {
                ui->listWidget->addItem(str.remove("[PACMAN]"));
            }
            if (str.contains(F2))
            {
                ui->listWidget->addItem(str.remove("[PACMAN]"));
                f = false;
            }
        }
    }
    file.close();
}
