#ifndef BASICTYPE_H
#define BASICTYPE_H


#include "idonnee.h"


template <typename T>
class BasicType : public IDonnee
{
public:
    BasicType(T v=T());
    BasicType<T>* copy() const;
    BasicType<T>* plus(const IDonnee*) const;
    BasicType<T>* minus(const IDonnee*) const;
    QString toString() const {return "";}

protected:
    T _v;
};


template <typename T>
BasicType<T>::BasicType(T v) : _v(v) {}


template <typename T>
BasicType<T>* BasicType<T>::copy() const {
    BasicType<T>* c = new BasicType<T>(_v);
    return c;
}

template <typename T>
BasicType<T>* BasicType<T>::plus(const IDonnee*o) const {
    BasicType<T>* p = dynamic_cast<BasicType<T>*>(o->copy());
    p->_v += _v;
    return p;
}

template <typename T>
BasicType<T>* BasicType<T>::minus(const IDonnee*o) const {
    BasicType<T>* p = dynamic_cast<BasicType<T>*>(o->copy());
    p->_v -= _v;
    return p;
}



#endif // BASICTYPE_H
