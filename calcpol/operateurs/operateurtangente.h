#ifndef OPERATEURTANGENTE_H
#define OPERATEURTANGENTE_H

#include "ioperateur.h"

class OperateurTangente : public IOperateur
{
public:
    OperateurTangente();
    QString toString() const;
    QRegExp regexp() const;
    OperateurTangente* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURTANGENTE_H
