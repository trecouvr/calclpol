#include "constants.h"

Rationnel::Rationnel(long num, long den) : IConstant(), _num(num), _den(den) {}


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
    return "Rationnel TODO";
}

QRegExp Rationnel::regexp() const {
    // TODO
    return QRegExp("");
}

Rationnel* Rationnel::copy() const {
    return new Rationnel(*this);
}
