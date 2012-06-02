#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "iconstant.h"

#include "qmath.h"

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
    BasicType(const Complex&);
    BasicType(const Rationnel&);
    BasicType(const IConstant &);
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
    QRegExp regexp() const;
    BasicType<T>* copy() const;

protected:
    void fromString(const QString &);
    T _v;
};


/**
  Classe représentant un complex, re+i*im.
*/
class Complex : public IConstant
{
public:
    Complex(const IConstant * re=0, const IConstant * im=0);
    template <typename T>
    Complex(const BasicType<T>& b);
    Complex(const Rationnel& r);
    Complex(const IConstant & i);
    operator long() const;
    operator double() const;
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


/**
  Classe représentant un rationnel : numerateur/denominateur.
*/
class Rationnel : public IConstant {
public:
    Rationnel(long num=0, long den=1);
    Rationnel(const IConstant & i);
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
#define TEMPLATE_CTE_TYPE(T) ((T(0.1)) ? IConstant::REEL : IConstant::ENTIER)

template <typename T>
Complex::Complex(const BasicType<T>& b) : IConstant(IConstant::COMPLEX), _re(b.copy()), _im(new BasicType<T>(0)) {}

template <typename T>
BasicType<T>::BasicType(double v) : IConstant(TEMPLATE_CTE_TYPE(T)), _v(v) {}

template <typename T> template<typename U>
BasicType<T>::BasicType(const BasicType<U>& u) : IConstant(TEMPLATE_CTE_TYPE(T)), _v(u._v) {}

template <typename T>
BasicType<T>::BasicType(const Complex& c) : IConstant(TEMPLATE_CTE_TYPE(T)), _v(T(c)) {}

template <typename T>
BasicType<T>::BasicType(const Rationnel& r) : IConstant(TEMPLATE_CTE_TYPE(T)), _v(T(r)) {}

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

template <typename T>
BasicType<T>::operator long() const {
    return (long) _v;
}

template <typename T>
BasicType<T>::operator double() const {
    return (double) _v;
}

#endif // CONSTANTS_H
