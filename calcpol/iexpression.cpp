#include "iexpression.h"

IExpression::IExpression() : _t(0) {
}

IExpression::IExpression(int t) : _t(t) {
}

int IExpression::t() const {
    return _t;
}
