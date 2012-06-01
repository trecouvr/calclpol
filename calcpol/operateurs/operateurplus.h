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
    IDonnee* exec(const QVector<IDonnee*>&) const;
};

#endif // OPERATEURPLUS_H
