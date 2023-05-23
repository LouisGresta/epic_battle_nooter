#include "mainwindow.h"
#include "battleground.h" //battleground include all other classes so don't need to add them
#include "qstd.h"


#include <QApplication>
#include <QString>
#include <QTextStream>

using namespace qstd;

void testToString(void)
{
}

void testCreationNooters()
{
#include <type_table.h>

    // Nooter The_original_noot("The Original Noot",
}

void testCreationJoueurs()
{
    Player Joueur1("Joueur 1");
    Player Joueur2("Joueur 2");
    qstd::cout << Joueur1.toString() << "\n";
    qstd::cout << Joueur2.toString() << "\n";
}

void testCreationTypes()
{
    //affichage du tableau des types
    cout << "Test Table" << endl;
    Type_table table;
    table.initTable();
}

/*void testCreationAttacks(){

    Attack defo1("deforestation" , "wallah je coupe des arbres", 1000, 0,0, ??);
    qstd::cout<<"defo 1:"<<defo1.getName()<<" descrition : "<<defo1.getDescription();
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    cout << "TestToString" << endl;
    testToString();
    testCreationJoueurs();
    testCreationTypes();
    //    testCreationAttacks();
    //    testCreationNooters();
    w.show();
    return a.exec();
}
