#include "operateurplus.h"

OperateurPlus::OperateurPlus() : IOperateur(2,true,true,true,true) {
}

IDonnee* OperateurPlus::exec(IDonnee**args) {
    return args[0]->plus(args[1]);
}


QString OperateurPlus::toString() const {
    return "-";
}
