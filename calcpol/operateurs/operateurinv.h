#ifndef OPERATEURInv_H
#define OPERATEURInv_H

#include "ioperateur.h"

class OperateurInv : public IOperateur
{
public:
	OperateurInv();
    QString toString() const;
    QRegExp regexp() const;
	OperateurInv* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURInv_H
