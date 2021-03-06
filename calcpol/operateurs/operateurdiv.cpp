#include "operateurdiv.h"

OperateurDiv::OperateurDiv() : IOperateur(2,true,true,true,true) {
}

IConstant* OperateurDiv::exec(const QVector<IConstant*>& args) const {
	if((double) *args[1] == 0)
		throw std::logic_error("On divise pas par 0 !");
	IConstant * r = args[0]->copy();
	*r /= *args[1];
    return r;
}


QString OperateurDiv::toString() const {
	return "/";
}

QRegExp OperateurDiv::regexp() const {
	return QRegExp("^/$");
}

OperateurDiv* OperateurDiv::copy() const {
	return new OperateurDiv(*this);
}
