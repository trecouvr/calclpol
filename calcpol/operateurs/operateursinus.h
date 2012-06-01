#ifndef OPERATEURSINUS_H
#define OPERATEURSINUS_H

#include "ioperateur.h"

class OperateurSinus : public IOperateur
{
public:
    OperateurSinus();
protected:
    IDonnee* exec(IDonnee **args);
    QString toString() const;
};

#endif // OPERATEURSINUS_H
