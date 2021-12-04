#include "oglwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    OglWindow w;
    w.show();

    return a.exec();
}
