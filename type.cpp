#include "type.h"
#include <QTextStream>
#include <tuple>

Type::Type(QString name, QList<Type_tuple> types_strenghts) : name(name), types_strenghts(types_strenghts)
{
}

Type Type::getType(int index) const
{
    return std::get<0>(types_strenghts[index]);
}

bool Type::isInTypes(Type type)
{
    std::tuple<Type, int, int> *tuple = nullptr;
    foreach (*tuple, types_strenghts)
    {
        if (std::get<0>(*tuple) == type)
        {
            return true;
        }
    }
    return false;
}

void Type::addType(std::tuple<Type, int, int> type)
{
    types_strenghts.append(type);
}

void Type::addTypes(QList<std::tuple<Type, int, int>> list)
{
    types_strenghts.append(list);
}

bool Type::operator==(Type type) const
{
    return name == type.name && types_strenghts == type.types_strenghts;
}
