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
    IDonnee* exec(const QVector<IDonnee*>&) const;
};

#endif // OPERATEURMINUS_H
