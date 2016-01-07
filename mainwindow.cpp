#include "mainwindow.h"
#include <string>
#include "ui_mainwindow.h"
#include "QPixmap"
#include "QPalette"
//#include "start.h"
#include <QtMultimedia/QMediaPlayer>

#include "superai.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   display_counter = "";
    red_counter_fordisplay = 0;
    black_counter_fordislpay = 0;
    ui->setupUi(this);
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            matrix[i][j] = 0;
    p_x=50;
    p_y=50;
    p_w=50;
    p_h=50;
    dist=20;
    click = false;
    gei = 0;

    this->label = new QLabel(this);
    this->label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    this->label->setGeometry(QRect ( QPoint(570,320) ,QSize(140,100) ) );

    //this->label->setText("Black");
    this->label->setStyleSheet("border:2px groove white;border-radius:10px;padding:2px 4px; color: black;");
    label->setVisible(display_counter);

    this->m_button = new QPushButton("Replay",this);

    this->m_button->setGeometry(QRect ( QPoint(570,70) ,QSize(100,50) ) );
    this->m_button->setStyleSheet("background-color: rgb(205,201,201);border:2px groove white;border-radius:10px;padding:2px 4px;");
    QFont qf("Courier", 15);
    QFont qe("Courier", 15);
    QFont qq("Courier",15, QFont::Bold);
    m_button->setFont((qf));
    label->setFont(qq);

    this->maker_button = new QPushButton("Credits",this);
    this->maker_button->setGeometry(QRect ( QPoint(570,150) ,QSize(100,50) ) );
    this->maker_button->setStyleSheet("background-color: rgb(205,201,201);border:2px groove white;border-radius:10px;padding:2px 4px;");
    maker_button->setFont((qf));

    this->bb_display = new QPushButton("Display\ncounters", this);
    this->bb_display->setGeometry(QRect(QPoint(570, 220), QSize(100, 80)));
    this->bb_display->setStyleSheet("background-color: rgb(205,201,201);border:2px groove white;border-radius:10px;padding:2px 4px;");
    bb_display->setFont((qe));

    connect(bb_display, SIGNAL(released()),this,SLOT(handleButton2()));
    connect(m_button,SIGNAL(released()),this,SLOT(handleButton()));
    connect(maker_button,SIGNAL(released()),this,SLOT(handleButton1()));


    this->setWindowTitle(QString::number(Data::flag));
    if(Data::flag == 1)
{
        //QFont pvp("Courier",QFont::Bold, 22);
        this->setWindowTitle(QString("PVP mode"));

 }
        else if(Data::flag == 2)
        this->setWindowTitle(QString("AI mode"));

    //show image
    QPixmap bg(":/new/prefix1/images/bakingsoda.jpeg");
    bg = bg.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bg);
    this->setPalette(palette);

    // play sound
    QMediaPlayer* music = new QMediaPlayer;
    music->setMedia(QUrl::fromLocalFile(":/new/prefix1/images/getlucky.mp3"));
    music->play();
    setWindowOpacity(0.92);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int
MainWindow::rowcounter(int i, int j, int matrix[Row][Colum]){
    int counter = 0;
    int color = matrix[i][j];
    int row=i,col=j;

    //row
    while(matrix[row][col-1] == color && (col-1) >= 0) {
        col--;
    }
    //this->setWindowTitle(QString::number(row)+" "+QString::number(col));
    while(matrix[row][col] == color && col<COL) {
        col++;
        counter++;
    }
    return counter;
}

int
MainWindow::colcounter(int i, int j, int matrix[Row][Colum]) {
    //col
    int counter = 0;
    int color = matrix[i][j];
    int row=i,col=j;

    while(matrix[row][col] == color && row < ROW) {
        row++;
        counter++;
        //this->setWindowTitle(QString::number(counter));
    }
    return counter;
}

int
MainWindow::leftcounter(int i, int j, int matrix[Row][Colum]) {
    //left diagonal
    int counter = 0;
    int color = matrix[i][j];
    int row=i,col=j;

    while(matrix[row-1][col-1] == color && ((col-1)>=0 && (row-1) >= 0) ) {
        row--;
        col--;
    }
    while(matrix[row][col] == color && (col < COL && row < ROW)) {
        row++;
        col++;
        counter++;
        //this->setWindowTitle(QString::number(counter));
    }
    return counter;
}

int
MainWindow::rightcounter(int i, int j, int matrix[Row][Colum]) {
    int counter = 0;
    int color = matrix[i][j];
    int row=i,col=j;

    while(matrix[row-1][col+1] == color && ((col+1) < COL && (row-1) >= 0) ) {
        row--;
        col++;
    }
    while(matrix[row][col]==color && (col >= 0 && row < ROW)) {
        row++;
        col--;
        counter++;
    }
    return counter;
}

int
MainWindow::counterget(int i, int j, int matrix[Row][Colum]) {
    int counter = 0;

    if(counter < rowcounter(i, j ,matrix))
        counter = rowcounter(i, j ,matrix);

    //cout<<i<<" "<<j<<" "<<counter<<" rowcounter"<<endl;

    if(counter < colcounter(i, j ,matrix))
        counter = colcounter(i, j ,matrix);

    //cout<<i<<" "<<j<<" "<<counter<<" colcounter"<<endl;

    if(counter < rightcounter(i, j ,matrix))
        counter = rightcounter(i, j ,matrix);

    //cout<<i<<" "<<j<<" "<<counter<<" rightcounter"<<endl;

    if(counter < leftcounter(i, j ,matrix))
        counter = leftcounter(i, j ,matrix);

    //cout<<i<<" "<<j<<" "<<counter<<" leftcounter"<<endl;



    return counter;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    resize(800,500);

    QPainter paint(this);
    //paint.setBrush(Qt::blue);
    paint.setPen(Qt::gray);
    //paint.drawLine(0,0,100,100);
    //paint.drawRect(0,0,1000,1000);
    //paint.setBrush(Qt::red);

        for(int i=0;i<ROW;i++)
            for(int j=0;j<COL;j++)
            {
                if(matrix[i][j] == 0)
                    //setIcon(QIcon(":/new/prefix1/images/read.png"));
                    paint.setBrush(Qt::white);

                else if(matrix[i][j] == 1)
                    paint.setBrush(Qt::black);
                else
                    paint.setBrush(Qt::red);
                paint.drawEllipse(p_x+j*(p_w+dist),p_y+i*(p_h+dist),p_w,p_h);
            }

}

int MainWindow::aiValue(int matrix[ROW][COL]) {
    superai *ai = new superai();
    ai->run(matrix);
    return ai->returnFunc();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(this->hasWin == false)
    {
        if(event->buttons() & Qt::LeftButton)
        {
            if(flag == 1)
            {
                int x,y;
                x = event->x();
                y = event->y();
                QString str = "x= "+QString::number(x)+" y="+QString::number(y);
                //statusBar()->showMessage(tr("hdsahjdkhaskdh")+str);
                //this->setWindowTitle(str);
                //matrix[2][3] = 1;
                //matrix[3][4] = 2;
                if(x<550 && x>30)
                {

                    int colu=0;

                    colu=(x-(p_x-dist/2))/(p_w+dist);

                    for(int i=5;i>=0;i--)
                    {
                        if(matrix[i][colu]==0)
                        {
                            if(click==false)
                                gei = 1;
                            else
                                gei = 2;
                            matrix[i][colu]=gei;
                            if(gei == 1)
                                black_counter_fordislpay = counterget(i,colu,matrix);

                            else
                                red_counter_fordisplay = counterget(i,colu,matrix);

                            //cout << black_counter_fordislpay << "black" << red_counter_fordisplay << "red" <<endl;
                            if((this->judge(i,colu)))
                            {
                                //this->setWindowTitle("Win!!!!!!!");
                                QString winText;
                                if(matrix[i][colu] == 1)
                                    winText = "black win";
                                else
                                    winText = "red win";
                                QMessageBox msgBox;
                                msgBox.setText(winText);
                                //msgBox.setInformativeText("win");
                                msgBox.setStandardButtons(QMessageBox::Ok);
                                msgBox.setDefaultButton(QMessageBox::Ok);
                                //msgBox.setFixedSize(150,150);
                                msgBox.exec();
                                hasWin = true;
                            }
                            click = !click;
                            break;

                        }
                    }
                }

                this->update();
            }// PVP mode
            else if(flag==2)
            {
                int x,y;
                x = event->x();
                y = event->y();
                //QString str = "x= "+QString::number(x)+" y="+QString::number(y);
                //statusBar()->showMessage(tr("hdsahjdkhaskdh")+str);
                //this->setWindowTitle(str);
                //matrix[2][3] = 1;
                //matrix[3][4] = 2;

                bool player_step=false;

                if(x<550 && x>30)
                {

                    int colu=0;
                    //int ai_colu = 0;
                    //int ai_pass = 0;
                    colu=(x-(p_x-dist/2))/(p_w+dist);



                    for(int i=5;i>=0;i--)
                    {
                        if(matrix[i][colu]==0)
                        {

                            matrix[i][colu]=1;// player step
                            player_step=true;

                            black_counter_fordislpay = counterget(i,colu,matrix);

                            if((this->judge(i,colu)))
                            {
                                //this->setWindowTitle("Win!!!!!!!");
                                QMessageBox msgBox;
                                msgBox.setText("player win");
                                //msgBox.setInformativeText("win");
                                msgBox.setStandardButtons(QMessageBox::Ok);
                                msgBox.setDefaultButton(QMessageBox::Ok);
                                //msgBox.setFixedSize(150,150);
                                msgBox.exec();
                                hasWin = true;
                            }



                            break;
                        }
                    }//player step

                    this->update();

                    if(hasWin == false && player_step==true){
                        //AI step

                        colu = aiValue(matrix);

                        //std::cout<<colu<<" colu"<<endl;

                        for(int i=5;i>=0;i--)
                        {

                            if(matrix[i][colu]==0)
                            {

                                matrix[i][colu]=2;// player step [i][colu]
                                red_counter_fordisplay = counterget(i,colu,matrix);
                                if((this->judge(i,colu)))
                                {
                                    //this->setWindowTitle("Win!!!!!!!");
                                    QMessageBox msgBox;
                                    msgBox.setText("AI win");
                                    //msgBox.setInformativeText("win");
                                    msgBox.setStandardButtons(QMessageBox::Ok);
                                    msgBox.setDefaultButton(QMessageBox::Ok);
                                    //msgBox.setFixedSize(150,150);
                                    msgBox.exec();
                                    hasWin = true;
                                }

                                break;

                            }
                        }
                    }// to detemind if player has win.

                }

                this->update();
            }//Ai mode

        }
        bool tail_flag = true;
        for(int i=0; i<7; i++) {
            if(matrix[0][i] == 0) {
                tail_flag = false;
                break;
            }
        }
        if(tail_flag) {
            QMessageBox tailbox;
            tailbox.setText("Draw");
            tailbox.exec();
        }

        display_cotent = "Black Counter: \n"+QString::number(black_counter_fordislpay)+"\nRed Counter:\n"+QString::number(red_counter_fordisplay);
        this->label->setText(display_cotent);
    }// to detemind if someone has win.

}

bool MainWindow::judge(int i,int j)
{
    int counter=0;
    int color=matrix[i][j];
    int row=i,col=j;
    bool u=false;

    //row
    while(matrix[row][col-1]==color && (col-1)>=0)
    {
        col--;
    }
    //this->setWindowTitle(QString::number(row)+" "+QString::number(col));
    while(matrix[row][col]==color && col<COL)
    {
        col++;
        counter++;
        //this->setWindowTitle(QString::number(counter));
        //cout<<counter<<endl;
        if(counter >= 4) {
            u = true;
        }
    }

    //col
    counter=0;
    row=i;
    col=j;
    while(matrix[row][col]==color && row<ROW)
    {
        row++;
        counter++;
        //this->setWindowTitle(QString::number(counter));
        if(counter >= 4) {
            u = true;
        }
    }

    //left diagonal
    counter=0;
    row=i;
    col=j;
    while(matrix[row-1][col-1]==color && ((col-1)>=0 && (row-1)>=0) )
    {
        row--;
        col--;
    }
    while(matrix[row][col]==color && (col<COL && row<ROW))
    {
        row++;
        col++;
        counter++;
        //this->setWindowTitle(QString::number(counter));
        if(counter >= 4) {
            u = true;
        }
    }

    counter=0;
    row=i;
    col=j;
    while(matrix[row-1][col+1]==color && ((col+1)<COL && (row-1)>=0) )
    {
        row--;
        col++;
    }
    while(matrix[row][col]==color && (col>=0 && row<ROW))
    {
        row++;
        col--;
        counter++;
        if(counter >= 4) {
            u = true;
        }
    }



    return u;
}

void MainWindow::handleButton2() {
  display_counter = !display_counter;
  this->label->setVisible(display_counter);
}

void MainWindow::handleButton1() {
    QMessageBox tailbox;

    tailbox.setText("Team: \tBaking Soada\n\nLearder:  \tHonglu Xu\n\nMembers: \tZhixin Liu\n\tQili Ou\n\tZekun Tang\n\tBoss");
    tailbox.exec();
}

void MainWindow::handleButton()
{
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            matrix[i][j] = 0;
    click = false;
    //this->setWindowTitle(QString::number(this->flag));
    this->update();
    hasWin = false;

}// replay button
/*
void MainWindow::setFlag(int n)
{
    flag = n;
}*/
