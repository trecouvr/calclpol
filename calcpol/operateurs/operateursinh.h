#ifndef OPERATEURSINH_H
#define OPERATEURSINH_H

#include "ioperateur.h"

class OperateurSinh : public IOperateur
{
public:
	OperateurSinh();
    QString toString() const;
    QRegExp regexp() const;
	OperateurSinh* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURSinh_H
