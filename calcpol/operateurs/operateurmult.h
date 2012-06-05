#ifndef OPERATEURMult_H
#define OPERATEURMult_H

#include "ioperateur.h"

class OperateurMult : public IOperateur
{
public:
	OperateurMult();
    QString toString() const;
    QRegExp regexp() const;
	OperateurMult* copy() const;

protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURMult_H
