#include "mainwindow.h"
#include "battleground.h"   //battleground include all other classes so don't need to add them
#include "qstd.h"

#include <QApplication>
#include <QString>
#include <QTextStream>

void test1V1(void) {

}

void testCreationNooters(){

    //Nooter The_original_noot("The Original Noot",

}

void testCreationJoueurs(){
    Player Joueur1(1 , "Joueur 1");
    Player Joueur2(2 , "Joueur 2");
    qstd::cout<<"Joueur 1 :"<<Joueur1.getId()<<" "<<Joueur1.getName()<<" Joueur 2 :"<<Joueur2.getId()<<" "<<Joueur2.getName();
}

/*void testCreationAttacks(){

    Attack defo1("deforestation" , "wallah je coupe des arbres", 1000, 0,0, ??);
    qstd::cout<<"defo 1:"<<defo1.getName()<<" descrition : "<<defo1.getDescription();
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();
//    return a.exec();
    test1V1();
    testCreationJoueurs();
//    testCreationAttacks();
//    testCreationNooters();

}
