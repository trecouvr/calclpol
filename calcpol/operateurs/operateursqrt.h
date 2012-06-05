#ifndef OPERATEURSqrt_H
#define OPERATEURSqrt_H

#include "ioperateur.h"

class OperateurSqrt : public IOperateur
{
public:
	OperateurSqrt();
    QString toString() const;
    QRegExp regexp() const;
	OperateurSqrt* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURSqrt_H
