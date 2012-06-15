#include "iconstant.h"
#include "qmath.h"

IConstant::IConstant(IConstant::T_CONSTANT t) : IExpression(IExpression::CONSTANT), _t_constant(t) {}

IConstant::T_CONSTANT IConstant::t_constant() const { return _t_constant; }

IConstant::~IConstant() {}

void IConstant::toDegres() {
    const IConstant * rad_to_deg = this->copy(180.0/M_PI);
    *this *= *rad_to_deg;
}

void IConstant::toRadians() {
    const IConstant * deg_to_rad = this->copy(M_PI/180.0);
    *this *= *deg_to_rad;
}
