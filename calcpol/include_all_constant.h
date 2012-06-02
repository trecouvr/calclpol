#ifndef INCLUDE_ALL_DONNEES_H
#define INCLUDE_ALL_DONNEES_H

#include "iconstant.h"

#include "qmath.h"

class Complex;
class Rationnel;

template <typename T>
class BasicType : public IConstant
{
public:
    BasicType(double v=0);
    BasicType(const Complex&);
    BasicType(const Rationnel&);
    BasicType<T>* plus(const IConstant*) const;
    BasicType<T>* minus(const IConstant*) const;
    BasicType<T>* sinus(bool rad=true) const;
    BasicType<T>* cosinus(bool rad=true) const;
    BasicType<T>* tangente(bool rad=true) const;
    QString toString() const;
    double toDouble() const;
    int toInt() const;
    operator int() const;
    BasicType<T>& operator+=(const IConstant&);
    BasicType<T>& operator-=(const IConstant&);
    BasicType<T>& operator/=(const IConstant&);
    QRegExp regexp() const;
    BasicType<T>* copy() const;

protected:
    void fromString(const QString &);
    T _v;
};
typedef BasicType<long>  Entier;
typedef BasicType<double>  Reel;

class Complex : public IConstant
{
public:
    Complex(const IConstant * re=0, const IConstant * im=0);
    template <typename T>
    Complex(const BasicType<T>& b);
    Complex(const Rationnel& r);
    Complex* copy() const;
    Complex* plus(const IConstant*) const;
    Complex* minus(const IConstant*) const;
    QString toString() const;
    Complex& operator+=(const IConstant&);
    Complex& operator-=(const IConstant&);
    Complex& operator/=(const IConstant&);
    const IConstant* re() const;

protected:
    void fromString(const QString &);
    QRegExp regexp() const;
    IConstant * _re;
    IConstant * _im;
};

class Rationnel : public IConstant {
public:
    Rationnel(long num=0, long den=1);
    Rationnel* copy() const;
    Rationnel* plus(const IConstant*) const;
    Rationnel* minus(const IConstant*) const;
    QString toString() const;
    Rationnel& operator+=(const IConstant&);
    Rationnel& operator-=(const IConstant&);
    Rationnel& operator/=(const IConstant&);
    operator long() const;
    operator double() const;
    long num() const;

protected:
    void fromString(const QString &);
    QRegExp regexp() const;
    long _num, _den;

};


template <typename T>
Complex::Complex(const BasicType<T>& b) : IConstant(), _re(b.copy()), _im(new BasicType<T>(0)) {}


template <typename T>
BasicType<T>::BasicType(double v) : IConstant(), _v(v) {}

template <typename T>
BasicType<T>::BasicType(const Complex& c) : IConstant(), _v(T(c.re())) {}

template <typename T>
BasicType<T>::BasicType(const Rationnel& r) : IConstant(), _v(r.num()) {}

template <typename T>
BasicType<T>::operator int() const {
    return (int)_v;
}

template <typename T>
BasicType<T>* BasicType<T>::plus(const IConstant*o) const {
    BasicType<T>* r = new BasicType<T>(*this);
    const BasicType<T>* p = dynamic_cast<const BasicType<T>*>(o);
    r->_v += p->_v;
    return r;
}

template <typename T>
BasicType<T>& BasicType<T>::operator+=(const IConstant& o) {
    const BasicType<T> p = dynamic_cast<const BasicType<T>&>(o);
    _v += p._v;
    return *this;
}

template <typename T>
BasicType<T>& BasicType<T>::operator-=(const IConstant& o) {
    const BasicType<T> p = dynamic_cast<const BasicType<T>&>(o);
    _v -= p._v;
    return *this;
}

template <typename T>
BasicType<T>& BasicType<T>::operator/=(const IConstant& o) {
    const BasicType<T> p = dynamic_cast<const BasicType<T>&>(o);
    _v /= p._v;
    return *this;
}


template <typename T>
BasicType<T>* BasicType<T>::minus(const IConstant*o) const {
    BasicType<T>* r = new BasicType<T>(*this);
    const BasicType<T>* p = dynamic_cast<const BasicType<T>*>(o);
    r->_v -= p->_v;
    return r;
}

template <typename T>
double BasicType<T>::toDouble() const {
    return (double) _v;
}

template <typename T>
int BasicType<T>::toInt() const {
    return (double) _v;
}

template <typename T>
QString BasicType<T>::toString() const {
    return QString::number(_v);
}

template <typename T>
BasicType<T>* BasicType<T>::sinus(bool rad) const {
    double r = sin(_v);
    if (!rad) {
        return new BasicType<T>((int)(r*180.0/M_PI));
    }
    else {
        return new BasicType<T>(r);
    }
}

template <typename T>
BasicType<T>* BasicType<T>::cosinus(bool rad) const {
    double r = cos(_v);
    if (!rad) {
        return new BasicType<T>((int)(r*180.0/M_PI));
    }
    else {
        return new BasicType<T>(r);
    }
}

template <typename T>
BasicType<T>* BasicType<T>::tangente(bool rad) const {
    double r = tan(_v);
    if (!rad) {
        return new BasicType<T>((int)(r*180.0/M_PI));
    }
    else {
        return new BasicType<T>(r);
    }
}

template <typename T>
QRegExp BasicType<T>::regexp() const {
    // TODO
    return QRegExp(".*");
}

template <typename T>
void BasicType<T>::fromString(const QString & s) {
    _v = s.toDouble();
}

template <typename T>
BasicType<T>* BasicType<T>::copy() const {
    return new BasicType<T>(*this);
}

#endif // INCLUDE_ALL_DONNEES_H
