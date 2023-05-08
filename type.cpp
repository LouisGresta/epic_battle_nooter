#include "type.h"
#include <tuple>

Type::Type(QString name, QList<std::tuple<Type, int, int>> types_strenghts) : name(name), types_strenghts(types_strenghts)
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

bool Type::isInWeakType(Type type)
{
    return weak_types.contains(type);
}

bool Type::isInStrongType(Type type)
{
    return strong_types.contains(type);
}
