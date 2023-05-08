#include "mainwindow.h"

#include "qstd.h"
using namespace qstd;

#include <QApplication>
#include <type_table.h>

void testToString(void) {

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    cout<<"Test Table"<<endl;
    Type_table table;
    table.initTable();

    cout<<"TestToString"<<endl;
    testToString();
    w.show();
    return a.exec();
}
