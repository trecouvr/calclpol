#include "iexpression.h"

IExpression::IExpression(IExpression::T_EXP t) : _t_exp(t) {}



IExpression::T_EXP IExpression::t_exp() const {
    return _t_exp;
}

void IExpression::fromString(const QString &) {}
