#include "start.h"
#include "ui_start.h"

//#include "mainwindow.h"

Start::Start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Start)
{
    //setWindowFlags(flags); // 设置禁止最大化
    setFixedSize(400,300); // 禁止改变窗口大小。;
    pvp = new QPushButton("PVP",this);
    ai = new QPushButton("AI",this);

    this->pvp->setGeometry(QRect( QPoint(25,75) ,QSize(150,150) ) );
    this->pvp->setStyleSheet("border:2px groove black;border-radius:10px;padding:2px 4px;");
    QFont qf("Courier", 25, QFont::Bold);
    pvp->setFont((qf));

    QPalette qp2;
    qp2.setColor(QPalette::Button, Qt::white);
    pvp->setPalette(qp2);
    pvp->setFlat((true));

    this->ai->setGeometry(QRect( QPoint(225,75) ,QSize(150,150) ) );
    this->ai->setStyleSheet("border:2px groove black;border-radius:10px;padding:2px 4px;");
    ai->setFont((qf));
    QPalette qp3;
    qp3.setColor(QPalette::Button, Qt::white);
    ai->setPalette(qp3);
    ai->setFlat(true);

    connect(pvp,SIGNAL(released()),this,SLOT(handleButton2()));
    connect(ai,SIGNAL(released()),this,SLOT(handleButton3()));
    //mainwindow.flag
    this->setWindowTitle( QString::number(mainwindow.flag) );

    QPixmap bg(":/new/prefix1/images/images.jpeg");

    bg = bg.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bg);
    this->setPalette(palette);

    ui->setupUi(this);
}

Start::~Start()
{
    delete ui;
}

void Start::handleButton2()
{

    //this->close();

    //this->setWindowTitle( QString::number(mainwindow.flag) );
    mainwindow.flag = 1;
    gamestart();
    mainwindow.setWindowTitle(QString("PVP mode"));
}

void Start::handleButton3()
{
    //this->close();
    mainwindow.flag = 2;
    //this->setWindowTitle( QString::number(flag) );
    gamestart();
    mainwindow.setWindowTitle(QString("AI mode"));
}

void Start::gamestart()
{
    mainwindow.show();
}
