#include "operateurln.h"


OperateurLn::OperateurLn() : IOperateur(1,true,true,true,false) {
}

IConstant* OperateurLn::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
	double r = log(v);
    return args[0]->copy(r);
}

QString OperateurLn::toString() const {
	return "ln";
}

QRegExp OperateurLn::regexp() const {
	return QRegExp("^ln$", Qt::CaseInsensitive);
}

OperateurLn* OperateurLn::copy() const {
	return new OperateurLn(*this);
}
