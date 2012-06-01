#include "complex.h"

Complex::Complex(const IDonnee* re, const IDonnee* im) : IDonnee() {
    if (re == 0) {
        _re = new BasicType<int>();
    }
    else {
        _re = re->copy();
    }
    if (im == 0) {
        _im = new BasicType<int>();
    }
    else {
        _im = im->copy();
    }
}

Complex* Complex::copy() const {
    return new Complex(_re,_im);
}

Complex* Complex::plus(const IDonnee*o) const {
    Complex* r = new Complex(*this);
    *r += *o;
    return r;
}

Complex* Complex::minus(const IDonnee*o) const {
    Complex* r = new Complex(*this);
    *r -= *o;
    return r;
}

Complex& Complex::operator+=(const IDonnee& o) {
    const Complex& p = dynamic_cast<const Complex&>(o);
    *_re += *(p._re);
    *_im += *(p._im);
    return *this;
}

Complex& Complex::operator-=(const IDonnee& o) {
    const Complex& p = dynamic_cast<const Complex&>(o);
    *_re -= *(p._re);
    *_im -= *(p._im);
    return *this;
}

Complex& Complex::operator/=(const IDonnee& /*o*/) {
    //const Complex& p = dynamic_cast<const Complex&>(o);
    // TODO
    return *this;
}

