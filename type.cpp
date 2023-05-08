#include "type.h"
#include <QTextStream>
#include <tuple>


Type::Type(QString name, QList<Type_tuple> types_strenghts):
    name(name), types_strenghts(types_strenghts)
{

}

QString Type::getName() const
{
    return name;
}

QString Type::getNameAtIndex(int index)
{
    return types_strenghts.at(index).name;
}

float Type::getAtkAtIndex(int index)
{
    return types_strenghts.at(index).coef;
}

bool Type::isInTypes(Type type)
{
    foreach (Type_tuple type_tuple, types_strenghts) {
        if( type_tuple.name == type.getName() )
            return true;
    }
    return false;
}

void Type::addType(Type_tuple tuple)
{
    types_strenghts.append(tuple);
}

void Type::addType(QList<Type_tuple> list_tuple)
{

}


/*Type Type::getType(int index) const
{
    return std::get<0>(types_strenghts[index]);
}

bool Type::isInTypes(Type type)
{
    std::tuple<Type, int, int> *tuple = nullptr;
    foreach (*tuple, types_strenghts) {
        if( std::get<0>(*tuple) == type ){
            return true;
        }
    }
    return false;
}

void Type::addType(std::tuple<Type, int, int> type)
{
    types_strenghts.append(type);
}

void Type::addTypes(QList<std::tuple<Type, int, int> > list)
{
    types_strenghts.append(list);
}

QString Type::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"Type "<<name<<" attaque : {";

    std::tuple<Type, int, int> *tuple;
    foreach (*tuple, types_strenghts) {
        buf<<&std::get<1>(*tuple)<<", ";
    }

    buf<<"} ; mauvais contre : {";
    foreach (*tuple, types_strenghts) {
        buf<<&std::get<2>(*tuple)<<", ";
    }
    buf<<"}";
    return res;
}

bool Type::operator==(Type type) const
{
    return name == type.getName();
}
*/
