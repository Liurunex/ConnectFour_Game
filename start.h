#ifndef START_H
#define START_H

#include <QDialog>
#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QPushButton>
#include "mainwindow.h"
#include "data.h"

namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();
    void gamestart();
    MainWindow mainwindow;

private slots:
    void handleButton2();
    void handleButton3();

private:
    Ui::Start *ui;
    QPushButton *pvp,*ai;
};

#endif // START_H
