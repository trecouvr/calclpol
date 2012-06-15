#include "operateursinh.h"


OperateurSinh::OperateurSinh() : IOperateur(1,true,true,true,false,true) {
}

IConstant* OperateurSinh::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
	double r = sinh(v);
    return args[0]->copy(r);
}

QString OperateurSinh::toString() const {
	return "sinh";
}

QRegExp OperateurSinh::regexp() const {
	return QRegExp("^sinh$", Qt::CaseInsensitive);
}

OperateurSinh* OperateurSinh::copy() const {
	return new OperateurSinh(*this);
}
