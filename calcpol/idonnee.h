#ifndef IDONNEE_H
#define IDONNEE_H


/**
  Meta classe des données
*/
class IDonnee
{
public:
    IDonnee();
    virtual void operator+=(const IDonnee&) = 0;
    virtual void operator-=(const IDonnee&) = 0;
    virtual void operator*=(const IDonnee&) = 0;
    virtual void operator/=(const IDonnee&) = 0;
};

#endif // IDONNEE_H
