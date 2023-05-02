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
    QString getName() const;
    QString toString();
    bool operator==(Type type) const;
};

#endif // TYPE_H
