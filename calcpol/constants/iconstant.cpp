#include "iconstant.h"

IConstant::IConstant() : IExpression(IExpression::CONSTANT) {}

IConstant* IConstant::sinus(bool /*rad*/) const {
    throw 42;
}

IConstant* IConstant::cosinus(bool /*rad*/) const {
    throw 42;
}

IConstant* IConstant::tangente(bool /*rad*/) const {
    throw 42;
}
