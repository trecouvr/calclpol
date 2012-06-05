#include "operateurminus.h"

OperateurMinus::OperateurMinus() : IOperateur(2,true,true,true,true) {
}

IConstant* OperateurMinus::exec(const QVector<IConstant*>& args) const {
    IConstant * r = args[0]->copy();
    *r += *args[1];
    return r;
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

