#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define ROW 6
#define COL 7

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QPushButton>
#include "data.h"
#include "superai.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool judge(int,int);
    void setFlag(int n);
    int flag;
    int aiValue(int matrix[ROW][COL]);


protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void handleButton();
    void handleButton1();
    void handleButton2();

private:
   // QPushButton *custButton(QString str,QString str1);
    int rowcounter(int i, int j, int matrix[Row][Colum]);
    int colcounter(int i, int j, int matrix[Row][Colum]);
    int leftcounter(int i, int j, int matrix[Row][Colum]);
    int rightcounter(int i, int j, int matrix[Row][Colum]);
    int counterget(int i, int j, int matrix[Row][Colum]);
    QPushButton *m_button;
    QPushButton *maker_button;
    QPushButton *bb_display;
    QLabel *label;
    //QPushButton *rr_display;
    Ui::MainWindow *ui;
    int matrix[ROW][COL];
    bool click;
    int p_x,p_y,p_w,p_h,dist;
    int gei;
    QString display_cotent;
    bool hasWin = false;
    bool display_counter = false;
    int red_counter_fordisplay = 0;
    int black_counter_fordislpay = 0;
};

#endif // MAINWINDOW_H
