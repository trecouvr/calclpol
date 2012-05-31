#include "complex.h"

Complex::Complex(double re, double im) : _re(re), _im(im) {}

Complex* Complex::copy() const {
    Complex* c = new Complex(_re,_im);
    return c;
}

Complex* Complex::plus(const IDonnee*o) const {
    Complex* p = dynamic_cast<Complex*>(o->copy());
    p->_re += _re;
    p->_im += _im;
    return p;
}

Complex* Complex::minus(const IDonnee*o) const {
    Complex* p = dynamic_cast<Complex*>(o->copy());
    p->_re -= _re;
    p->_im -= _im;
    return p;
}

