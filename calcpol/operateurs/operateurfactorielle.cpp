#include "operateurfactorielle.h"


OperateurFactorielle::OperateurFactorielle() : IOperateur(1,true,false,false,false) {
}

long fact(long n)
{
	if(n<=1) { return n; }
	return n * fact(n-1);
}

IConstant* OperateurFactorielle::exec(const QVector<IConstant*>& args) const {
	Logger::v("OperateurFactorielle", "exec()");
	long v = (long) *args[0];
	double r = fact(v);
    return args[0]->copy(r);
}

QString OperateurFactorielle::toString() const {
	return "!";
}

QRegExp OperateurFactorielle::regexp() const {
	return QRegExp("^!$", Qt::CaseInsensitive);
}

OperateurFactorielle* OperateurFactorielle::copy() const {
	return new OperateurFactorielle(*this);
}
