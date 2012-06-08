#include "complex.h"
#include "basictype.h"
#include "rationnel.h"
#include <QStringList>

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
    case IConstant::RATIONNEL:
        _re = new Rationnel(dynamic_cast<const Rationnel&>(i));
        _im = new Rationnel(0);
        break;
    }
}

Complex::Complex(const Complex &o) : IConstant(IConstant::COMPLEX), _re(o.re()->copy()), _im(o.im()->copy()) {}

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

Complex& Complex::operator*=(const IConstant& o) {
	const Complex& p = dynamic_cast<const Complex&>(o);
	double re = (((double) *(_re) * (double) *(p)._re) - ((double) *(_im) * (double) *(p)._im));
	double im = (((double) *(_re) * (double) *(p)._im) + ((double) *(_im) * (double) *(p)._re));
	IConstant * retmp = _re->copy(re);
	IConstant * imtmp = _im->copy(im);
	delete _re;
	delete _im;
	_re = retmp;
	_im = imtmp;
	return *this;
}


void Complex::fromString(const QString & s) {
    const QRegExp re_entier = Entier().regexp();
    const QRegExp re_reel = Reel().regexp();
    const QRegExp re_rationnel = Rationnel().regexp();
    QRegExp re = this->regexp();
    if (re.exactMatch(s)) {
        QStringList l = re.capturedTexts();
        QString s_re = l[1];
        QString s_im = l[4];
        if (l[3] == "-") {
            s_im = "-"+s_im;
        }
        if (re_entier.exactMatch(s_re)) {
            delete _re;
            _re = new Entier();
            _re->fromString(s_re);
        }
        else if (re_reel.exactMatch(s_re)) {
            delete _re;
            _re = new Reel();
            _re->fromString(s_re);
        }
        else if (re_rationnel.exactMatch(s_re)) {
            delete _re;
            _re = new Rationnel();
            _re->fromString(s_re);
        }
        else {
            Logger::e("Complex", "fromString, impossible de parser re : '"+s+"'.");
        }
        if (re_entier.exactMatch(s_im)) {
            delete _im;
            _im = new Entier();
            _im->fromString(s_im);
        }
        else if (re_reel.exactMatch(s_im)) {
            delete _im;
            _im = new Reel();
            _im->fromString(s_im);
        }
        else if (re_rationnel.exactMatch(s_im)) {
            delete _im;
            _im = new Rationnel();
            _im->fromString(s_im);
        }
        else {
            Logger::e("Complex", "fromString, impossible de parser re : '"+s+"'.");
        }
    }
    else {
        Logger::e("Complex", "fromString, impossible de parser '"+s+"'.");
    }
}

QString Complex::toString() const {
    if (_re and _im)
        return _re->toString()+"+"+_im->toString()+"i";
    else
        Logger::e("Complex", "toString, _im or _re null");
        return 0;
}

QRegExp Complex::regexp() const {
    return QRegExp("(-?[^+-]+)(([+-])([^i]+)i)?");
}

Complex* Complex::copy() const {
    return new Complex(*this);
}

Complex* Complex::copy(double v) const {
    IConstant * re = _re->copy(v);
    return new Complex(re);
}

Complex::operator double() const {
    return (double) *_re;
}

Complex::operator long() const {
    return (long) *_re;
}
