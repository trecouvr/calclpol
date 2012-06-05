#ifndef OPERATEURSqr_H
#define OPERATEURSqr_H

#include "ioperateur.h"

class OperateurSqr : public IOperateur
{
public:
	OperateurSqr();
    QString toString() const;
    QRegExp regexp() const;
	OperateurSqr* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURSqr_H
