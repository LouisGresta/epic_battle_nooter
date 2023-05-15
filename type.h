#ifndef TYPE_H
#define TYPE_H

#include "type_tuple.h"

#include <QList>
#include <QString>

class Type
{
public:
    Type(QString name,
         QList<Type_tuple> types_strenghts = QList<Type_tuple>());

    QString getName() const;
    QString getNameAtIndex(int index);
    float getAtkAtIndex(int index);
    float getDefAtIndex(int index);

    bool isInTypes(Type type);

    void addType(Type_tuple tuple);

    void setType(const Type &newType);
    QString toString();
    bool operator==(Type type) const;

private:
    QString name;
    QList<Type_tuple> types_strenghts;
};

#endif // TYPE_H
