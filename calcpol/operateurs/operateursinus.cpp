#include "operateursinus.h"


OperateurSinus::OperateurSinus() : IOperateur(1,true,true,true,false,true) {
}

IConstant* OperateurSinus::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
    double r = sin(v);
    return args[0]->copy(r);
}

QString OperateurSinus::toString() const {
    return "sin";
}

QRegExp OperateurSinus::regexp() const {
    return QRegExp("^sin$", Qt::CaseInsensitive);
}

OperateurSinus* OperateurSinus::copy() const {
    return new OperateurSinus(*this);
}
