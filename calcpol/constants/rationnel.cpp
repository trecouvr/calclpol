#include "constants.h"
#define CONST_CONVERSION 10000

Rationnel::Rationnel(long num, long den) : IConstant(IConstant::RATIONNEL), _num(num), _den(den) {}

Rationnel::Rationnel(const Rationnel& o) : IConstant(IConstant::RATIONNEL), _num(o._num), _den(o._den) {}

Rationnel::Rationnel(const IConstant & i) : IConstant(IConstant::RATIONNEL) {
    switch (i.t_constant()) {
    case IConstant::COMPLEX:
        if (dynamic_cast<const Complex&>(i).re()->t_constant() == IConstant::RATIONNEL) {
            _num = dynamic_cast<const Rationnel*>(dynamic_cast<const Complex&>(i).re())->_num;
            _den = dynamic_cast<const Rationnel*>(dynamic_cast<const Complex&>(i).re())->_den;
            break;
        }
    case IConstant::ENTIER:
        _num = (long) i;
        _den = 1;
        break;
	case IConstant::REEL:
		_num = (long) ((double) i * CONST_CONVERSION);
		_den = CONST_CONVERSION;
		simplifier();
		break;
    case IConstant::RATIONNEL:
        _num = dynamic_cast<const Rationnel&>(i)._num;
        _den = dynamic_cast<const Rationnel&>(i)._den;
        break;
    }
}


Rationnel::operator long() const { return (long)(_num/_den); }
Rationnel::operator double() const { return (double)(_num/_den); }

Rationnel* Rationnel::plus(const IConstant*o) const {
    Rationnel* r = new Rationnel(*this);
    *r += *o;
    return r;
}

Rationnel* Rationnel::minus(const IConstant*o) const {
    Rationnel* r = new Rationnel(*this);
    *r -= *o;
    return r;
}

Rationnel& Rationnel::operator+=(const IConstant& o) {
    const Rationnel& p = dynamic_cast<const Rationnel&>(o);
    _num = _num*p._den + _den*p._num;
    _den = _den*p._den;
    return *this;
}

Rationnel& Rationnel::operator-=(const IConstant& o) {
    const Rationnel& p = dynamic_cast<const Rationnel&>(o);
    _num = _num*p._den - _den*p._num;
    _den = _den*p._den;
    return *this;
}

Rationnel& Rationnel::operator/=(const IConstant& /*o*/) {
    //const Rationnel& p = dynamic_cast<const Rationnel&>(o);
    // TODO
    return *this;
}

Rationnel& Rationnel::operator/=(int x) {
    _den *= x;
    return *this;
}

Rationnel& Rationnel::operator*=(const IConstant& o) {
	const Rationnel& p = dynamic_cast<const Rationnel&>(o);
	_den *= p._den;
	_num *= p._num;
	return *this;
}

long pgcd(long a,long b)
{
	return b ?  pgcd(b,a%b) : a;
}

#define abs(x) ((x) > 0 ? (x) : -(x))

void Rationnel::simplifier() {
	Logger::v("Rationnel","simplifier()");
	long p = pgcd(abs(_den),abs(_num));
	_den = _den / p;
	_num = _den / p;
}

void Rationnel::fromString(const QString &) {
    // TODO
}

QString Rationnel::toString() const {
    return "("+QString::number(_num)+"/"+QString::number(_den)+")";
}

QRegExp Rationnel::regexp() const {
    return QRegExp("(-?\\d+)(/-?\\d+)?");
}

Rationnel* Rationnel::copy() const {
    return new Rationnel(*this);
}

Rationnel* Rationnel::copy(double d) const {
	Logger::v("Rationnel","copy(double)");
	Rationnel* r = new Rationnel(*this);
	r->_num = (long) (d * CONST_CONVERSION);
	r->_den = CONST_CONVERSION;
	r->simplifier();
	return r;
}
