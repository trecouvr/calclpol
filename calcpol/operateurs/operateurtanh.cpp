#include "operateurtanh.h"


OperateurTanh::OperateurTanh() : IOperateur(1,true,true,true,false,true) {
}

IConstant* OperateurTanh::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
	double r = tanh(v);
    return args[0]->copy(r);
}

QString OperateurTanh::toString() const {
	return "tanh";
}

QRegExp OperateurTanh::regexp() const {
	return QRegExp("^tanh$", Qt::CaseInsensitive);
}

OperateurTanh* OperateurTanh::copy() const {
	return new OperateurTanh(*this);
}
