#ifndef OPERATEURMINUS_H
#define OPERATEURMINUS_H

#include "ioperateur.h"

class OperateurMinus : public IOperateur
{
public:
    OperateurMinus();
protected:
    IDonnee* exec(IDonnee **args);
};

#endif // OPERATEURMINUS_H
