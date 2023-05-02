#include "type.h"

#include <QTextStream>

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

QString Type::getName() const
{
    return name;
}

bool Type::operator==(Type type) const
{
    return name == type.name;
}

QString Type::toString()
{
    QString res;
    QTextStream buf(&res);

    buf << name + "\n\tweaker against : ";
    foreach (Type type, strong_types) {
        buf << type.name;
        if (!strong_types.endsWith(type))
            buf << ", ";
    }
    buf << "\n\tstronger against : ";
    foreach (Type type, weak_types) {
        buf << type.name;
        if (!strong_types.endsWith(type))
            buf << ", ";
    }
    return res;
}
