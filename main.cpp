#include "mainwindow.h"
#include "battleground.h" //battleground include all other classes so don't need to add them
#include "qstd.h"

#include <QApplication>
#include <QString>
#include <QTextStream>

using namespace qstd;

Type_table table;

void testToString(void)
{
}

void testCreationNooters()
{
    Attack defo1("deforestation" , "wallah je coupe des arbres", 1000, 0,0,table.getType("Herbe"));
    Attack defo2("DEFORESTATION" , "encore mieux", 2000, 0,0,table.getType("Herbe"));
    Attack defo3("DEFORESTATION !" , "encore mieux", 3000, 0,0,table.getType("Herbe"));
    Attack defo4("DEFORESTATION !!!" , "encore mieux", 4000, 0,0,table.getType("Herbe"));

    QList<Attack> liste_atk_n = QList<Attack>({defo1,defo2,defo3,defo4});
    Nooter nootnoot("The_Original_Nooter" , table.getType("Herbe"),liste_atk_n ,10000,20,10,100 );
    cout<<"test nooters \n"<<nootnoot.toString();

    cout<<"\n test type name : "<< table.getType("Herbe").getName();

}

void testCreationJoueurs()
{
    Player Joueur1("Joueur 1");
    Player Joueur2("Joueur 2");
    cout << Joueur1.toString() << "\n";
    cout << Joueur2.toString() << "\n";
}

void testCreationTypes()
{
    // affichage du tableau des types
    cout << "Test Table" << endl;
}

void testCreationAttacks()
{

    Attack defo1("deforestation" , "wallah je coupe des arbres", 1000, 0,0,table.getType("Herbe"));

    cout<<"test attack \n"<<defo1.toString();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    cout << "TestToString" << endl;
    testToString();
    testCreationJoueurs();

    testCreationAttacks();
    testCreationNooters();
    w.show();
    return a.exec();
}
