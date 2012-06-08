#ifndef COMPLEX_H
#define COMPLEX_H


#include "iconstant.h"

/**
  Classe représentant un complex, re+i*im.
*/
class Complex : public IConstant
{
public:
    Complex(const IConstant * re=0, const IConstant * im=0);
    Complex(const IConstant & i);
    Complex(const Complex&);
    ~Complex();
    operator long() const;
    operator double() const;
    Complex* copy() const;
    Complex* copy(double) const;
    Complex* plus(const IConstant*) const;
    Complex* minus(const IConstant*) const;
    QString toString() const;
    Complex& operator+=(const IConstant&);
    Complex& operator-=(const IConstant&);
    Complex& operator/=(const IConstant&);
    Complex& operator/=(int);
    Complex& operator*=(const IConstant&);
    const IConstant* re() const;
    const IConstant* im() const;
    void re(const IConstant*);
    void im(const IConstant*);
    QRegExp regexp() const;

protected:
    void fromString(const QString &);
    IConstant * _re;
    IConstant * _im;
};

#endif // COMPLEX_H
