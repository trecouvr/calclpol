#ifndef OPERATEURSINUS_H
#define OPERATEURSINUS_H

#include "ioperateur.h"

class OperateurSinus : public IOperateur
{
public:
    OperateurSinus();
    QString toString() const;
    QRegExp regexp() const;
    OperateurSinus* copy() const;
protected:
    IDonnee* exec(const QVector<IDonnee*>&) const;
};

#endif // OPERATEURSINUS_H
