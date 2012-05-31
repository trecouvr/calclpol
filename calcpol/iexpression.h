#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <QString>

class IExpression
{
public:
    enum {CONSTANT, OPERATOR, EXPRESSION};
    IExpression();
    IExpression(int t);
    int t() const;
    virtual void fromString(const QString&) = 0;
    virtual QString toString() const = 0;

private:
    int _t;
};

#endif // IEXPRESSION_H
