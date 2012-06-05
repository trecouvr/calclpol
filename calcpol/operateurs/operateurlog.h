#ifndef OPERATEURLog_H
#define OPERATEURLog_H

#include "ioperateur.h"

class OperateurLog : public IOperateur
{
public:
	OperateurLog();
    QString toString() const;
    QRegExp regexp() const;
	OperateurLog* copy() const;
protected:
    IConstant* exec(const QVector<IConstant*>&) const;
};

#endif // OPERATEURLog_H
