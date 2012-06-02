#include "include_all_constant.h"

Complex::Complex(const IConstant* re, const IConstant* im) : IConstant() {
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

Complex::Complex(const Rationnel &r) : IConstant(), _re(r.copy()), _im(new Rationnel()) {}

const IConstant* Complex::re() const { return _re; }

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


void Complex::fromString(const QString &) {
    // TODO
}

QString Complex::toString() const {
    return "Complex TODO";
}

QRegExp Complex::regexp() const {
    // TODO
    return QRegExp("");
}

Complex* Complex::copy() const {
    return new Complex(*this);
}
