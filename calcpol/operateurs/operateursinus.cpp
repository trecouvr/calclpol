#include "operateursinus.h"


OperateurSinus::OperateurSinus() : IOperateur(1,true,true,true,false) {
}

IDonnee* OperateurSinus::exec(const QVector<IDonnee*>& args) const {
    return args[0]->sinus();
}

QString OperateurSinus::toString() const {
    return "sin";
}

QRegExp OperateurSinus::regexp() const {
    return QRegExp("^\\-$");
}

OperateurSinus* OperateurSinus::copy() const {
    return new OperateurSinus(*this);
}
