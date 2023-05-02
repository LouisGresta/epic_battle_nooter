#include "type.h"

Type::Type(QString name, Type *strong_types, Type *weak_types):
    name(name), strong_types(strong_types), weak_types(weak_types)
{

}

Type Type::getStrongType(int index) const
{
    return strong_types[index];
}

Type Type::getWeakType(int index) const
{
    return weak_types[index];
}
