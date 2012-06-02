#ifndef IOPERATEUR_H
#define IOPERATEUR_H

#include "include_all_constant.h"

#include <QVector>

class IOperateur : public IExpression
{
public:
    IOperateur(int u, bool allow_entier, bool allow_reel, bool allow_rationnelle, bool allow_complex);
    unsigned int unarite() const;
    IConstant* exec(unsigned int mode, const QVector<IConstant*>&) const;

protected:
    virtual IConstant* exec(const QVector<IConstant*>&) const = 0;
    unsigned int _unarite;
    void fromString(const QString &);
    QVector<bool> _allowed_datas;
};

#endif // IOPERATEUR_H
