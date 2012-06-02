#include "operateursinus.h"


OperateurSinus::OperateurSinus() : IOperateur(1,true,true,true,false) {
}

IConstant* OperateurSinus::exec(const QVector<IConstant*>& args) const {
    return args[0]->sinus();
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
