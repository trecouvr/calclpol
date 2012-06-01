#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <QString>
#include <QRegExp>

class IExpression
{
public:
    enum {CONSTANT, OPERATOR, EXPRESSION};
    IExpression(int t, const QRegExp&);
    int t() const;
    virtual QString toString() const = 0;

private:
    int _t;
    QRegExp _regexp;
};

#endif // IEXPRESSION_H
