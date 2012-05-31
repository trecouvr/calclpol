#ifndef COMPLEX_H
#define COMPLEX_H

#include "idonnee.h"

class Complex : public IDonnee
{
public:
    Complex();
    void operator+=(const IDonnee&) {};
    void operator-=(const IDonnee&) {};
    void operator*=(const IDonnee&) {};
    void operator/=(const IDonnee&) {};
};

#endif // COMPLEX_H
