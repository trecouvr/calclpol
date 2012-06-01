#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <QString>
#include <QRegExp>

class IExpression
{
public:
    enum {CONSTANT, OPERATOR, EXPRESSION};
    IExpression(int t=0);
    virtual IExpression* copy() const = 0;
    int t() const;
    virtual QString toString() const = 0;
    virtual void fromString(const QString&);
    virtual QRegExp regexp() const = 0;

protected:
    int _t;
    QRegExp _regexp;
};

#endif // IEXPRESSION_H
