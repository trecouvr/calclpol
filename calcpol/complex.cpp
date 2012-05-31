#include "complex.h"

Complex::Complex(const IDonnee* re, const IDonnee* im) {
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
    Complex* c = new Complex(_re,_im);
    return c;
}

Complex* Complex::plus(const IDonnee*o) const {
    Complex* p = dynamic_cast<Complex*>(o->copy());
    p->_re->plus(_re);
    p->_im->plus(_im);
    return p;
}

Complex* Complex::minus(const IDonnee*o) const {
    Complex* p = dynamic_cast<Complex*>(o->copy());
    p->_re->minus(_re);
    p->_im->minus(_im);
    return p;
}

