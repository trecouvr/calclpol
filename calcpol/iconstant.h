#ifndef IDONNEE_H
#define IDONNEE_H


#include "iexpression.h"

/**
  Meta classe des données
*/
class IConstant : public IExpression
{
public:
    enum {ENTIER, REEL, RATIONNELLE, COMPLEX};
    IConstant();
    virtual IConstant& operator+=(const IConstant&) = 0;
    virtual IConstant& operator-=(const IConstant&) = 0;
    virtual IConstant& operator/=(const IConstant&) = 0;
    virtual IConstant* plus(const IConstant*) const = 0;
    virtual IConstant* minus(const IConstant*) const = 0;
    //virtual IDonnee* multiply(const IDonnee*) const = 0;
    //virtual IDonnee* div(const IDonnee*) const = 0;
    virtual IConstant* sinus(bool rad=true) const;
    virtual IConstant* cosinus(bool rad=true) const;
    virtual IConstant* tangente(bool rad=true) const;
    virtual double toDouble() const;
    virtual int toInt() const;

};


#endif // IDONNEE_H
