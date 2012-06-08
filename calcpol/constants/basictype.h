#ifndef BASICTYPE_H
#define BASICTYPE_H

#include "iconstant.h"

#include "qmath.h"

#include "complex.h"
#include "rationnel.h"

class Complex;
class Rationnel;

/**
  Classe manipulant des types simples (int, long, float, double),
  elle est utilisée pour Entier (BasicType<long>) et Reel (BasicType<double>).
*/
template <typename T>
class BasicType : public IConstant
{
    template <typename U> friend class BasicType;
public:
    BasicType(double v=0);
    template <typename U> BasicType(const BasicType<U>&);
    BasicType(const IConstant &);
    BasicType(const BasicType<T>&);
    operator long() const;
    operator double() const;
    BasicType<T>* plus(const IConstant*) const;
    BasicType<T>* minus(const IConstant*) const;
    BasicType<T>* sinus(bool rad=true) const;
    BasicType<T>* cosinus(bool rad=true) const;
    BasicType<T>* tangente(bool rad=true) const;
    QString toString() const;
    BasicType<T>& operator+=(const IConstant&);
    BasicType<T>& operator-=(const IConstant&);
    BasicType<T>& operator/=(const IConstant&);
    BasicType<T>& operator/=(int);
    BasicType<T>& operator*=(const IConstant&);
    QRegExp regexp() const;
    BasicType<T>* copy() const;
    BasicType<T>* copy(double) const;

protected:
    void fromString(const QString &);
    T _v;
};




typedef BasicType<long>  Entier;
typedef BasicType<double>  Reel;



/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                     TEMPLATE BasicType<T>
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// le template doit être défini dans le .h
//
// tricks pour déterminer le type de constante du template
// si le template est entier (utilise des int ou des long), alors 0.1 sera arrondi à 0 et la condition sera fausse
#define TEMPLATE_REEL(T) T(0.1)
#define TEMPLATE_CTE_TYPE(T) ((T(0.1)) ? IConstant::REEL : IConstant::ENTIER)


template <typename T>
BasicType<T>::BasicType(double v) : IConstant(TEMPLATE_CTE_TYPE(T)), _v(v) {}

template <typename T>
BasicType<T>::BasicType(const BasicType<T>& o) : IConstant(TEMPLATE_CTE_TYPE(T)), _v(o._v) {}

template <typename T> template<typename U>
BasicType<T>::BasicType(const BasicType<U>& u) : IConstant(TEMPLATE_CTE_TYPE(T)), _v(u._v) {}

template <typename T>
BasicType<T>::BasicType(const IConstant & i) : IConstant(TEMPLATE_CTE_TYPE(T)), _v(T(i)) {}

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
BasicType<T>& BasicType<T>::operator/=(int x) {
    _v /= x;
    return *this;
}

template <typename T>
BasicType<T>& BasicType<T>::operator*=(const IConstant& o) {
	const BasicType<T> p = dynamic_cast<const BasicType<T>&>(o);
	_v *= p._v;
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
    return TEMPLATE_REEL(T) ? QRegExp("(-?\\d+(\\.\\d+)?)") : QRegExp("(-?\\d+)");
}

template <typename T>
void BasicType<T>::fromString(const QString & s) {
    _v = s.toDouble();
}

template <typename T>
BasicType<T>* BasicType<T>::copy() const {
    return new BasicType<T>(*this);
}

template <typename T>
BasicType<T>* BasicType<T>::copy(double v) const {
    return new BasicType<T>(v);
}

template <typename T>
BasicType<T>::operator long() const {
    return (long) _v;
}

template <typename T>
BasicType<T>::operator double() const {
    return (double) _v;
}

#endif // CONSTANTS_H
