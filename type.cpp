#include "type.h"

Type::Type()
{

}

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



