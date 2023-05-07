#include "type.h"
#include <tuple>


Type::Type(QString name, QList<std::tuple<Type, int, int> > types_strenghts):
    name(name), types_strenghts(types_strenghts)
{

}

Type Type::getType(int index) const
{
    return std::get<0>(types_strenghts[index]);
}

bool Type::isInTypes(Type type)
{
    return types_strenghts.contains(type);
}

void Type::addType(std::tuple<Type, int, int> type)
{
    types_strenghts.append(type);
}

void Type::addTypes(QList<std::tuple<Type, int, int> > list)
{
    types_strenghts.append(list);
}
