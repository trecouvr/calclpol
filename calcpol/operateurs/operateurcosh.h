#ifndef OPERATEURCosh_H
#define OPERATEURCosh_H

#include "ioperateur.h"

class OperateurCosh : public IOperateur
{
public:
    OperateurCosh();
    QString toString() const;
    QRegExp regexp() const;
    OperateurCosh* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURCosh_H
