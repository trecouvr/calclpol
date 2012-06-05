#ifndef OPERATEURLn_H
#define OPERATEURLn_H

#include "ioperateur.h"

class OperateurLn : public IOperateur
{
public:
	OperateurLn();
    QString toString() const;
    QRegExp regexp() const;
	OperateurLn* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURLn_H
