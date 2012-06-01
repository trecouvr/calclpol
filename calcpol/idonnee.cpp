#include "idonnee.h"

IDonnee::IDonnee() : IExpression(IExpression::CONSTANT) {}

IDonnee::~IDonnee() {}

double IDonnee::toDouble() const {
    throw 42;
}

int IDonnee::toInt() const {
    throw 42;
}

IDonnee* IDonnee::sinus(bool /*rad*/) const {
    throw 42;
}

IDonnee* IDonnee::cosinus(bool /*rad*/) const {
    throw 42;
}

IDonnee* IDonnee::tangente(bool /*rad*/) const {
    throw 42;
}
