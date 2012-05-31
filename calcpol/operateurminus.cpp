#include "operateurminus.h"

OperateurMinus::OperateurMinus() : IOperateur(2,true,true,true,true) {
}

IDonnee* OperateurMinus::exec(IDonnee**args) {
    return args[0]->minus(args[1]);
}

