#include "operateurplus.h"

OperateurPlus::OperateurPlus() : IOperateur(2,true,true,true,true) {
}

IConstant* OperateurPlus::exec(const QVector<IConstant*>& args) const {
    IConstant * r = args[0]->copy();
    *r += *args[1];
    return r;
}


QString OperateurPlus::toString() const {
    return "-";
}

QRegExp OperateurPlus::regexp() const {
    return QRegExp("^\\+$");
}

OperateurPlus* OperateurPlus::copy() const {
    return new OperateurPlus(*this);
}
