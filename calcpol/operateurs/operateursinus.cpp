#include "operateursinus.h"


OperateurSinus::OperateurSinus() : IOperateur(1,true,true,true,false) {
}

IDonnee* OperateurSinus::exec(IDonnee**args) {
    return args[0]->sinus();
}

QString OperateurSinus::toString() const {
    return "sin";
}
