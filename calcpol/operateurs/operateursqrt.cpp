#include "operateursqrt.h"


OperateurSqrt::OperateurSqrt() : IOperateur(1,true,true,true,false) {
}

IConstant* OperateurSqrt::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
	double r = sqrt(v);
    return args[0]->copy(r);
}

QString OperateurSqrt::toString() const {
	return "sqrt";
}

QRegExp OperateurSqrt::regexp() const {
	return QRegExp("^sqrt$", Qt::CaseInsensitive);
}

OperateurSqrt* OperateurSqrt::copy() const {
	return new OperateurSqrt(*this);
}
