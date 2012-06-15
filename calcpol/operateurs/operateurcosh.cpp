#include "operateurcosh.h"


OperateurCosh::OperateurCosh() : IOperateur(1,true,true,true,false,true) {
}

IConstant* OperateurCosh::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
	double r = cosh(v);
    return args[0]->copy(r);
}

QString OperateurCosh::toString() const {
	return "cosh";
}

QRegExp OperateurCosh::regexp() const {
	return QRegExp("^cosh$", Qt::CaseInsensitive);
}

OperateurCosh* OperateurCosh::copy() const {
	return new OperateurCosh(*this);
}
