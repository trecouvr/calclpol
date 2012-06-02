#ifndef COMPLEX_H
#define COMPLEX_H

#include "iconstant.h"
#include "basictype.h"

class Complex : public IConstant
{
public:
    Complex();
    //Complex(const IDonnee * re=0, const IDonnee * im=0);
    Complex* copy() const;
    Complex* plus(const IConstant*) const;
    Complex* minus(const IConstant*) const;
    QString toString() const;
    Complex& operator+=(const IConstant&);
    Complex& operator-=(const IConstant&);
    Complex& operator/=(const IConstant&);

protected:
    void fromString(const QString &);
    QRegExp regexp() const;
    IConstant * _re;
    IConstant * _im;
};

#endif // COMPLEX_H
