#include "operateurtangente.h"



OperateurTangente::OperateurTangente() : IOperateur(1,true,true,true,false) {
}

IConstant* OperateurTangente::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
    double r = sin(v);
    return args[0]->copy(r);
}

QString OperateurTangente::toString() const {
    return "sin";
}

QRegExp OperateurTangente::regexp() const {
    return QRegExp("^sin$", Qt::CaseInsensitive);
}

OperateurTangente* OperateurTangente::copy() const {
    return new OperateurTangente(*this);
}
