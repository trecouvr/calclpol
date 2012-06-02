#include "constants.h"

Rationnel::Rationnel(long num, long den) : IConstant(IConstant::RATIONNELLE), _num(num), _den(den) {}

Rationnel::Rationnel(const IConstant & i) : IConstant(IConstant::RATIONNELLE) {
    switch (i.t_constant()) {
    case IConstant::COMPLEX:
        if (dynamic_cast<const Complex&>(i).re()->t_constant() == IConstant::RATIONNELLE) {
            _num = dynamic_cast<const Rationnel*>(dynamic_cast<const Complex&>(i).re())->_num;
            _den = dynamic_cast<const Rationnel*>(dynamic_cast<const Complex&>(i).re())->_den;
            break;
        }
    case IConstant::ENTIER:
    case IConstant::REEL:
        _num = (long) i;
        _den = 1;
        break;
    case IConstant::RATIONNELLE:
        _num = dynamic_cast<const Rationnel&>(i)._num;
        _den = dynamic_cast<const Rationnel&>(i)._den;
        break;
    }
}


Rationnel::operator long() const { return (long)(_num/_den); }
Rationnel::operator double() const { return (double)(_num/_den); }

Rationnel* Rationnel::plus(const IConstant*o) const {
    Rationnel* r = new Rationnel(*this);
    // TODO
    return r;
}

Rationnel* Rationnel::minus(const IConstant*o) const {
    Rationnel* r = new Rationnel(*this);
    // TODO
    return r;
}

Rationnel& Rationnel::operator+=(const IConstant& o) {
    const Rationnel& p = dynamic_cast<const Rationnel&>(o);
    // TODO
    return *this;
}

Rationnel& Rationnel::operator-=(const IConstant& o) {
    const Rationnel& p = dynamic_cast<const Rationnel&>(o);
    // TODO
    return *this;
}

Rationnel& Rationnel::operator/=(const IConstant& /*o*/) {
    //const Rationnel& p = dynamic_cast<const Rationnel&>(o);
    // TODO
    return *this;
}


void Rationnel::fromString(const QString &) {
    // TODO
}

QString Rationnel::toString() const {
    return QString::number(_num)+"/"+QString::number(_den);
}

QRegExp Rationnel::regexp() const {
    // TODO
    return QRegExp("");
}

Rationnel* Rationnel::copy() const {
    return new Rationnel(*this);
}
