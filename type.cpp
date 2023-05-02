#include "type.h"

Type::Type(QString name, QList<Type> strong_types, QList<Type> weak_types):
    name(name), strong_types(strong_types), weak_types(weak_types)
{

}

Type Type::getStrongType(int index) const
{
    return strong_types.at(index);
}

Type Type::getWeakType(int index) const
{
    return weak_types.at(index);
}

bool Type::isInWeakType(Type type)
{
    return weak_types.contains(type);
}

bool Type::isInStrongType(Type type)
{
    return strong_types.contains(type);
}

