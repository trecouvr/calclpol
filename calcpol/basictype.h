#ifndef BASICTYPE_H
#define BASICTYPE_H


#include "idonnee.h"
#include "qmath.h"


template <typename T>
class BasicType : public IDonnee
{
public:
    BasicType(int v);
    BasicType(double v=0);
    BasicType<T>* copy() const;
    BasicType<T>* plus(const IDonnee*) const;
    BasicType<T>* minus(const IDonnee*) const;
    BasicType<T>* sinus(bool rad=true) const;
    BasicType<T>* cosinus(bool rad=true) const;
    BasicType<T>* tangente(bool rad=true) const;
    QString toString() const;
    double toDouble() const;
    int toInt() const;
    operator int() const;
    BasicType<T>& operator+=(const IDonnee&);
    BasicType<T>& operator-=(const IDonnee&);
    BasicType<T>& operator/=(const IDonnee&);

protected:
    T _v;
};


template <typename T>
BasicType<T>::BasicType(int v) : IDonnee(QRegExp()), _v(v) {}

template <typename T>
BasicType<T>::BasicType(double v) : IDonnee(QRegExp()), _v(v) {}


template <typename T>
BasicType<T>::operator int() const {
    return (int)_v;
}

template <typename T>
BasicType<T>* BasicType<T>::copy() const {
    return new BasicType<T>(_v);
}

template <typename T>
BasicType<T>* BasicType<T>::plus(const IDonnee*o) const {
    BasicType<T>* r = new BasicType<T>(*this);
    const BasicType<T>* p = dynamic_cast<const BasicType<T>*>(o);
    r->_v += p->_v;
    return r;
}

template <typename T>
BasicType<T>& BasicType<T>::operator+=(const IDonnee& o) {
    const BasicType<T> p = dynamic_cast<const BasicType<T>&>(o);
    _v += p._v;
    return *this;
}

template <typename T>
BasicType<T>& BasicType<T>::operator-=(const IDonnee& o) {
    const BasicType<T> p = dynamic_cast<const BasicType<T>&>(o);
    _v -= p._v;
    return *this;
}

template <typename T>
BasicType<T>& BasicType<T>::operator/=(const IDonnee& o) {
    const BasicType<T> p = dynamic_cast<const BasicType<T>&>(o);
    _v /= p._v;
    return *this;
}


template <typename T>
BasicType<T>* BasicType<T>::minus(const IDonnee*o) const {
    BasicType<T>* p = dynamic_cast<BasicType<T>*>(o->copy());
    p->_v -= _v;
    return p;
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
    return "BasicType TODO";
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



#endif // BASICTYPE_H
