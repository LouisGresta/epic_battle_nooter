#ifndef INITPARAMETEREXCEPTION_H
#define INITPARAMETEREXCEPTION_H

#include <QString>
#include <exception>

class InitParameterException : public std::exception
{
private:
    int parameterIndex;  // Entier spécifiant l'index du premier parametre levant l'exception.
public:
    QString message = "ParameterError : One or more init parameters are incorrects.";
    InitParameterException(int c) : parameterIndex(c) {}
    InitParameterException(const InitParameterException &source) : parameterIndex(source.parameterIndex) {}
    QString getMessage() { return message + " first occurence : " + QChar(parameterIndex); }
};

#endif // INITPARAMETEREXCEPTION_H
