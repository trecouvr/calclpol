#include "operateurplus.h"

OperateurPlus::OperateurPlus() : IOperateur(2,true,true,true,true) {
}

IConstant* OperateurPlus::exec(const QVector<IConstant*>& args) const {
    return args[0]->plus(args[1]);
}


QString OperateurPlus::toString() const {
    return "-";
}

QRegExp OperateurPlus::regexp() const {
    return QRegExp("^\\-$");
}

OperateurPlus* OperateurPlus::copy() const {
    return new OperateurPlus(*this);
}
