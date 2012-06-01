#ifndef COMPLEX_H
#define COMPLEX_H

#include "idonnee.h"
#include "basictype.h"

class Complex : public IDonnee
{
public:
    Complex(const IDonnee * re=0, const IDonnee * im=0);
    Complex* copy() const;
    Complex* plus(const IDonnee*) const;
    Complex* minus(const IDonnee*) const;
    QString toString() const {return "";}
    Complex& operator+=(const IDonnee&);
    Complex& operator-=(const IDonnee&);
    Complex& operator/=(const IDonnee&);

protected:
    IDonnee * _re;
    IDonnee * _im;
};

#endif // COMPLEX_H
