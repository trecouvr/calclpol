#include "entier.h"

Entier::Entier(int v) : _v(v) {}


Entier* Entier::copy() const {
    Entier* c = new Entier(_v);
    return c;
}

Entier* Entier::plus(const IDonnee*o) const {
    Entier* p = dynamic_cast<Entier*>(o->copy());
    p->_v += _v;
    return p;
}

Entier* Entier::minus(const IDonnee*o) const {
    Entier* p = dynamic_cast<Entier*>(o->copy());
    p->_v -= _v;
    return p;
}
