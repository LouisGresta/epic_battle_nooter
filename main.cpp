#include "mainwindow.h"

#include <QApplication>

void testToString(void) {

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    testToString();
    w.show();
    return a.exec();
}
