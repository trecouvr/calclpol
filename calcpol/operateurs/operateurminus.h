#ifndef OPERATEURMINUS_H
#define OPERATEURMINUS_H

#include "ioperateur.h"

class OperateurMinus : public IOperateur
{
public:
    OperateurMinus();
    QString toString() const;
    QRegExp regexp() const;
    OperateurMinus* copy() const;

protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURMINUS_H
