#include "iexpression.h"

IExpression::IExpression(int t) : _t(t) {
}


int IExpression::t() const {
    return _t;
}
