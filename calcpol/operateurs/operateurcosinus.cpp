#include "operateurcosinus.h"


OperateurCosinus::OperateurCosinus() : IOperateur(1,true,true,true,false,true) {
}

IConstant* OperateurCosinus::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
    double r = cos(v);
    return args[0]->copy(r);
}

QString OperateurCosinus::toString() const {
    return "cos";
}

QRegExp OperateurCosinus::regexp() const {
    return QRegExp("^cos$", Qt::CaseInsensitive);
}

OperateurCosinus* OperateurCosinus::copy() const {
    return new OperateurCosinus(*this);
}
