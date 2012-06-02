#ifndef BASICTYPE_H
#define BASICTYPE_H


#include "iconstant.h"
#include "qmath.h"


template <typename T>
class BasicType : public IConstant
{
public:
    BasicType();
    explicit BasicType(int);
    explicit BasicType(double);
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


template <typename T>
BasicType<T>::BasicType() : IConstant() {}

template <typename T>
BasicType<T>::BasicType(int v) : IConstant(), _v(v) {}

template <typename T>
BasicType<T>::BasicType(double v) : IConstant(), _v(v) {}


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

#endif // BASICTYPE_H
