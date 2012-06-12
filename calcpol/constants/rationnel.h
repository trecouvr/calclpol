#ifndef RATIONNEL_H
#define RATIONNEL_H


#include "iconstant.h"

/**
  Classe représentant un rationnel : numerateur/denominateur.
*/
class Rationnel : public IConstant {
public:
    Rationnel(long num=0, long den=1);
    Rationnel(const IConstant & i);
    Rationnel(const Rationnel&);
    Rationnel* copy() const;
    Rationnel* copy(double) const;
    Rationnel* plus(const IConstant*) const;
    Rationnel* minus(const IConstant*) const;
    QString toString() const;
    Rationnel& operator+=(const IConstant&);
    Rationnel& operator-=(const IConstant&);
    Rationnel& operator/=(const IConstant&);
    Rationnel& operator/=(int);
    Rationnel& operator*=(const IConstant&);
    operator long() const;
    operator double() const;
    long num() const;
    void simplifier();
    QRegExp regexp() const;
    static long pgcd(long,long);

protected:
    void fromString(const QString &);
    long _num, _den;

};

#endif // RATIONNEL_H
