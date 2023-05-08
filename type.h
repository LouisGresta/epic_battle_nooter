#ifndef TYPE_H
#define TYPE_H

#include <QList>
#include <QString>

class Type
{
private:
    QString name;
    QList<std::tuple<Type, int, int>> types_strenghts;

public:
    Type(QString name,
         QList<std::tuple<Type, int, int>> types_strenghts = QList<std::tuple<Type, int, int>>());
    Type getType(int index) const;
    void addType(std::tuple<Type, int, int> type);
    void addTypes(QList<std::tuple<Type, int, int>> list);
    bool operator==(Type type) const;
    QString getName() const;
};

#endif // TYPE_H
