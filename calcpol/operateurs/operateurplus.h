#ifndef OPERATEURPLUS_H
#define OPERATEURPLUS_H

#include "ioperateur.h"

class OperateurPlus : public IOperateur
{
public:
    OperateurPlus();
protected:
    IDonnee* exec(IDonnee **args);
};

#endif // OPERATEURPLUS_H
