#ifndef IOPERATEUR_H
#define IOPERATEUR_H

#include "include_all_donnees.h"

#include <QVector>

class IOperateur : public IExpression
{
public:
    IOperateur(int u, bool allow_entier, bool allow_reel, bool allow_rationnelle, bool allow_complex);
    unsigned int unarite() const;
    IDonnee* exec(unsigned int mode, const QVector<IDonnee*>&) const;

protected:
    virtual IDonnee* exec(const QVector<IDonnee*>&) const = 0;
    unsigned int _unarite;
    void fromString(const QString &);
    QVector<bool> _allowed_datas;
};

#endif // IOPERATEUR_H
