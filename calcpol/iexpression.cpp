#include "iexpression.h"

IExpression::IExpression(int t, const QRegExp& re) : _t(t), _regexp(re) {
}


int IExpression::t() const {
    return _t;
}
