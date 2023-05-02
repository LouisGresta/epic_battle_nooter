#ifndef TYPE_H
#define TYPE_H

#include <QList>
#include <QString>



class Type
{
private:
    QString name;
    QList<Type> strong_types;
    QList<Type> weak_types;
public:
    Type(QString name, QList<Type> strong_types, QList<Type> weak_types);
    Type getStrongType(int index) const;
    Type getWeakType(int index) const;
    bool isInWeakType(Type type);
    bool isInStrongType(Type type);
};

#endif // TYPE_H
