#include "operateurlog.h"


OperateurLog::OperateurLog() : IOperateur(1,true,true,true,false) {
}

IConstant* OperateurLog::exec(const QVector<IConstant*>& args) const {
    double v = (double) *args[0];
	double r = log10(v);
    return args[0]->copy(r);
}

QString OperateurLog::toString() const {
	return "log";
}

QRegExp OperateurLog::regexp() const {
	return QRegExp("^log$", Qt::CaseInsensitive);
}

OperateurLog* OperateurLog::copy() const {
	return new OperateurLog(*this);
}
