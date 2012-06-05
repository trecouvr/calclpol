#ifndef OPERATEURTanh_H
#define OPERATEURTanh_H

#include "ioperateur.h"

class OperateurTanh : public IOperateur
{
public:
	OperateurTanh();
    QString toString() const;
    QRegExp regexp() const;
	OperateurTanh* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURTanh_H
