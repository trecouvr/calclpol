#include "operateursqr.h"


OperateurSqr::OperateurSqr() : IOperateur(1,true,true,true,true) {
}

IConstant* OperateurSqr::exec(const QVector<IConstant*>& args) const {
	IConstant * r = args[0]->copy();
	*r *= *r;
	return r;
}

QString OperateurSqr::toString() const {
	return "sqr";
}

QRegExp OperateurSqr::regexp() const {
	return QRegExp("^sqr$", Qt::CaseInsensitive);
}

OperateurSqr* OperateurSqr::copy() const {
	return new OperateurSqr(*this);
}
