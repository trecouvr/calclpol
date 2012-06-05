#include "operateurcube.h"


OperateurCube::OperateurCube() : IOperateur(1,true,true,true,true) {
}

IConstant* OperateurCube::exec(const QVector<IConstant*>& args) const {
	IConstant * r = args[0]->copy();
	*r *= *r;
	*r *= *r;
	return r;
}

QString OperateurCube::toString() const {
	return "cube";
}

QRegExp OperateurCube::regexp() const {
	return QRegExp("^cube$", Qt::CaseInsensitive);
}

OperateurCube* OperateurCube::copy() const {
	return new OperateurCube(*this);
}
