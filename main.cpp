#include "robowindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoboWindow w;
    w.show();
    return a.exec();
}
