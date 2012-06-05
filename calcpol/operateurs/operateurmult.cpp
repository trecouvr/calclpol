#include "operateurmult.h"

OperateurMult::OperateurMult() : IOperateur(2,true,true,true,true) {
}

IConstant* OperateurMult::exec(const QVector<IConstant*>& args) const {
    IConstant * r = args[0]->copy();
	*r *= *args[1];
    return r;
}


QString OperateurMult::toString() const {
	return "*";
}

QRegExp OperateurMult::regexp() const {
	return QRegExp("^\\*$");
}

OperateurMult* OperateurMult::copy() const {
	return new OperateurMult(*this);
}
