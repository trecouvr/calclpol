#ifndef COMPLEX_H
#define COMPLEX_H

#include "idonnee.h"

class Complex : public IDonnee
{
public:
    Complex(double re=0, double im=0);
    Complex* copy() const;
    Complex* plus(const IDonnee*) const;
    Complex* minus(const IDonnee*) const;
    void fromString(const QString &) {}
    QString toString() const {return "";}

protected:
    double _re, _im;
};

#endif // COMPLEX_H
