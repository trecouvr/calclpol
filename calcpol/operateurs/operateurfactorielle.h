#ifndef OPERATEURFACTORIELLE_H
#define OPERATEURFACTORIELLE_H

#include "ioperateur.h"

class OperateurFactorielle : public IOperateur
{
public:
	OperateurFactorielle();
    QString toString() const;
    QRegExp regexp() const;
	OperateurFactorielle* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURFactorielle_H
