#ifndef OPERATEURCube_H
#define OPERATEURCube_H

#include "ioperateur.h"

class OperateurCube : public IOperateur
{
public:
	OperateurCube();
    QString toString() const;
    QRegExp regexp() const;
	OperateurCube* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURCube_H
