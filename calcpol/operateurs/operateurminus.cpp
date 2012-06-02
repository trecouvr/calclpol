#include "operateurminus.h"

OperateurMinus::OperateurMinus() : IOperateur(2,true,true,true,true) {
}

IConstant* OperateurMinus::exec(const QVector<IConstant*>& args) const {
    return args[0]->minus(args[1]);
}


QString OperateurMinus::toString() const {
    return "-";
}

QRegExp OperateurMinus::regexp() const {
    return QRegExp("^\\-$");
}

OperateurMinus* OperateurMinus::copy() const {
    return new OperateurMinus(*this);
}

