#ifndef ENTIER_H
#define ENTIER_H

#include "idonnee.h"

class Entier : public IDonnee
{
public:
    Entier();
    Entier(int v=0);
    Entier* copy() const;
    Entier* plus(const IDonnee*) const;
    Entier* minus(const IDonnee*) const;
    void fromString(const QString &) {}
    QString toString() const {return "";}

protected:
    int _v;
};

#endif // ENTIER_H
