#include "type.h"
#include <QTextStream>
#include <tuple>

Type::Type(QString name, QList<Type_tuple> types_strenghts) : name(name), types_strenghts(types_strenghts)
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
    foreach (Type_tuple type_tuple, types_strenghts)
    {
        if (type_tuple.name == type.getName())
            return true;
    }
    return false;
}

void Type::addType(Type_tuple tuple)
{
    types_strenghts.append(tuple);
}

bool Type::operator==(Type type) const
{
    return name == type.name;
}
