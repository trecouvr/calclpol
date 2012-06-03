#include "iconstant.h"

IConstant::IConstant(IConstant::T_CONSTANT t) : IExpression(IExpression::CONSTANT), _t_constant(t) {}

IConstant::T_CONSTANT IConstant::t_constant() const { return _t_constant; }

IConstant::~IConstant() {}

IConstant* IConstant::sinus(bool /*rad*/) const {
    throw 42;
}

IConstant* IConstant::cosinus(bool /*rad*/) const {
    throw 42;
}

IConstant* IConstant::tangente(bool /*rad*/) const {
    throw 42;
}
