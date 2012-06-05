#ifndef OPERATEURCOSINUS_H
#define OPERATEURCOSINUS_H

#include "ioperateur.h"

class OperateurCosinus : public IOperateur
{
public:
    OperateurCosinus();
    QString toString() const;
    QRegExp regexp() const;
    OperateurCosinus* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};


#endif // OPERATEURCOSINUS_H
