#ifndef COMPLEX_H
#define COMPLEX_H

#include "idonnee.h"
#include "basictype.h"

class Complex : public IDonnee
{
public:
    Complex();
    //Complex(const IDonnee * re=0, const IDonnee * im=0);
    Complex* copy() const;
    Complex* plus(const IDonnee*) const;
    Complex* minus(const IDonnee*) const;
    QString toString() const;
    Complex& operator+=(const IDonnee&);
    Complex& operator-=(const IDonnee&);
    Complex& operator/=(const IDonnee&);

protected:
    void fromString(const QString &);
    QRegExp regexp() const;
    IDonnee * _re;
    IDonnee * _im;
};

#endif // COMPLEX_H
