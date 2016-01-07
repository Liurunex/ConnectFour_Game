#include "mainwindow.h"
#include "start.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Start st;

    st.show();

    return a.exec();
}
