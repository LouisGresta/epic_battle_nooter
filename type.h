#ifndef TYPE_H
#define TYPE_H

#include <QString>



class Type
{
private:
    QString name;
    Type *strong_types;
    Type *weak_types;
public:
    Type(QString, Type*, Type*);
    Type getStrongType(int) const;
    Type getWeakType(int) const;
};

#endif // TYPE_H
