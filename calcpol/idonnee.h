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
    virtual ~IDonnee();
    virtual IDonnee* copy() const = 0;
    virtual IDonnee* plus(const IDonnee*) const = 0;
    virtual IDonnee* minus(const IDonnee*) const = 0;
};


#endif // IDONNEE_H
