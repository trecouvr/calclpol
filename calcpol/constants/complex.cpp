#include "constants.h"

Complex::Complex(const IConstant* re, const IConstant* im) : IConstant(IConstant::COMPLEX) {
    if (re == 0) {
        _re = new Entier(0);
    }
    else {
        _re = re->copy();
    }
    if (im == 0) {
        _im = new Entier(0);
    }
    else {
        _im = im->copy();
    }
}

Complex::Complex(const Rationnel &r) : IConstant(IConstant::COMPLEX), _re(r.copy()), _im(new Rationnel()) {}


Complex::Complex(const IConstant & i) : IConstant(IConstant::COMPLEX) {
    switch (i.t_constant()) {
    case IConstant::ENTIER:
        _re = new Entier(dynamic_cast<const Entier&>(i));
        _im = new Entier(0);
        break;
    case IConstant::REEL:
        _re = new Reel(dynamic_cast<const Reel&>(i));
        _im = new Reel(0);
        break;
    case IConstant::COMPLEX:
        _re = dynamic_cast<const Complex&>(i)._re->copy();
        _im = dynamic_cast<const Complex&>(i)._im->copy();
        break;
    case IConstant::RATIONNELLE:
        _re = new Rationnel(dynamic_cast<const Rationnel&>(i));
        _im = new Rationnel(0);
        break;
    }
}

Complex::~Complex() {
    delete _re;
    delete _im;
}

const IConstant* Complex::re() const { return _re; }
const IConstant* Complex::im() const { return _im; }
void Complex::re(const IConstant * c) {
    delete _re;
    _re = c->copy();
}
void Complex::im(const IConstant * c) {
    delete _im;
    _im = c->copy();
}

Complex* Complex::plus(const IConstant*o) const {
    Complex* r = new Complex(*this);
    *r += *o;
    return r;
}

Complex* Complex::minus(const IConstant*o) const {
    Complex* r = new Complex(*this);
    *r -= *o;
    return r;
}

Complex& Complex::operator+=(const IConstant& o) {
    const Complex& p = dynamic_cast<const Complex&>(o);
    *_re += *(p._re);
    *_im += *(p._im);
    return *this;
}

Complex& Complex::operator-=(const IConstant& o) {
    const Complex& p = dynamic_cast<const Complex&>(o);
    *_re -= *(p._re);
    *_im -= *(p._im);
    return *this;
}

Complex& Complex::operator/=(const IConstant& /*o*/) {
    //const Complex& p = dynamic_cast<const Complex&>(o);
    // TODO
    return *this;
}

Complex& Complex::operator/=(int x) {
    *_re /= x;
    *_im /= x;
    return *this;
}


void Complex::fromString(const QString &) {
    // TODO
}

QString Complex::toString() const {
    if (_re and _im)
        return _re->toString()+"i"+_im->toString();
    else
        Logger::e("Complex", "toString, _im or _re null");
        return 0;
}

QRegExp Complex::regexp() const {
    // TODO
    return QRegExp("");
}

Complex* Complex::copy() const {
    return new Complex(*this);
}

Complex::operator double() const {
    return (double) *_re;
}

Complex::operator long() const {
    return (long) *_re;
}
