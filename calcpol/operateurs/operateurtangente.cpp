#include "operateurtangente.h"



OperateurTangente::OperateurTangente() : IOperateur(1,true,true,true,false,true) {
}

IConstant* OperateurTangente::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
    double r = sin(v);
    return args[0]->copy(r);
}

QString OperateurTangente::toString() const {
	return "tan";
}

QRegExp OperateurTangente::regexp() const {
	return QRegExp("^tan$", Qt::CaseInsensitive);
}

OperateurTangente* OperateurTangente::copy() const {
    return new OperateurTangente(*this);
}
