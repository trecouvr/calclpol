#ifndef IDONNEE_H
#define IDONNEE_H


#include "iexpression.h"

/**
  Meta classe des données
*/
class IDonnee : public IExpression
{
public:
    enum {ENTIER, REEL, RATIONNELLE, COMPLEX};
    IDonnee();
    virtual IDonnee& operator+=(const IDonnee&) = 0;
    virtual IDonnee& operator-=(const IDonnee&) = 0;
    virtual IDonnee& operator/=(const IDonnee&) = 0;
    virtual IDonnee* plus(const IDonnee*) const = 0;
    virtual IDonnee* minus(const IDonnee*) const = 0;
    //virtual IDonnee* multiply(const IDonnee*) const = 0;
    //virtual IDonnee* div(const IDonnee*) const = 0;
    virtual IDonnee* sinus(bool rad=true) const;
    virtual IDonnee* cosinus(bool rad=true) const;
    virtual IDonnee* tangente(bool rad=true) const;
    virtual double toDouble() const;
    virtual int toInt() const;

};


#endif // IDONNEE_H
