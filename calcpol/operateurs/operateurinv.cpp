#include "operateurinv.h"
#include "logger.h"

OperateurInv::OperateurInv() : IOperateur(1,true,true,true,false) {
}

IConstant* OperateurInv::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
	double r = 1/v;
    return args[0]->copy(r);
}

QString OperateurInv::toString() const {
	return "inv";
}

QRegExp OperateurInv::regexp() const {
	return QRegExp("^inv$", Qt::CaseInsensitive);
}

OperateurInv* OperateurInv::copy() const {
	return new OperateurInv(*this);
}
