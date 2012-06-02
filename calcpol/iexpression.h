#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <QString>
#include <QRegExp>

class IExpression
{
public:
    enum T_EXP {CONSTANT, OPERATOR, EXPRESSION};
    explicit IExpression(T_EXP t);
    virtual IExpression* copy() const = 0;
    IExpression::T_EXP t_exp() const;
    virtual QString toString() const = 0;
    virtual void fromString(const QString&);
    virtual QRegExp regexp() const = 0;

protected:
    T_EXP _t_exp;
    QRegExp _regexp;
};

#endif // IEXPRESSION_H
