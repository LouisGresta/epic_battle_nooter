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
    Type();
    Type(QString name, QList<Type> strong_types, QList<Type> weak_types);
    Type getStrongType(int index) const;
    Type getWeakType(int index) const;

};

#endif // TYPE_H
