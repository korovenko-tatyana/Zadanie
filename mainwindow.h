#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int Check = 1;

private slots:
    void PacOut();
    //void ChangeDirection();
    void Filter();
    void GroupTime();
    void GroupRunning();
};

#endif // MAINWINDOW_H
