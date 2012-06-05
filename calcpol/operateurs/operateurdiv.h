#ifndef OPERATEURDiv_H
#define OPERATEURDiv_H

#include "ioperateur.h"

class OperateurDiv : public IOperateur
{
public:
	OperateurDiv();
    QString toString() const;
    QRegExp regexp() const;
	OperateurDiv* copy() const;

protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURDiv_H
