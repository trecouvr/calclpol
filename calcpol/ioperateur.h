#ifndef IOPERATEUR_H
#define IOPERATEUR_H

#include "include_all_donnees.h"

#include <QVector>

class IOperateur : public IExpression
{
public:
    IOperateur(const QRegExp& re, int u, bool allow_entier, bool allow_reel, bool allow_rationnelle, bool allow_complex);
    unsigned int unarite() const;
    IDonnee* exec(unsigned int mode, IDonnee**args);

protected:
    virtual IDonnee* exec(IDonnee**args) = 0;
    unsigned int _unarite;
    QVector<bool> _allowed_datas;
};

#endif // IOPERATEUR_H
