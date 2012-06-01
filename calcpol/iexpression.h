#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <QString>
#include <QRegExp>

class IExpression
{
public:
    enum {CONSTANT, OPERATOR, EXPRESSION};
    IExpression(int t);
    int t() const;
    virtual QString toString() const = 0;

private:
    int _t;
};

#endif // IEXPRESSION_H
