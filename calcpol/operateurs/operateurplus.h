#ifndef OPERATEURPLUS_H
#define OPERATEURPLUS_H

#include "ioperateur.h"

class OperateurPlus : public IOperateur
{
public:
    OperateurPlus();
    QString toString() const;
    QRegExp regexp() const;
    OperateurPlus* copy() const;

protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURPLUS_H
