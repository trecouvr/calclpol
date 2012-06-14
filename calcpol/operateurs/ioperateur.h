#ifndef IOPERATEUR_H
#define IOPERATEUR_H

#include "constants/constants.h"

#include <QVector>

class IOperateur : public IExpression
{
public:
    IOperateur(int u, bool allow_entier, bool allow_reel, bool allow_rationnel, bool allow_complex);
    virtual ~IOperateur();
    unsigned int unarite() const;
    /**
      Application de l'opérateur aux IConstant*, test que le mode en cours est valide, puis
      appelle la fonctions interne exec(const QVector&).
      @param mode
      @param {const QVector<IConstant*>} args
      @return {IConstant*} result
    */
    IConstant* exec(unsigned int mode, const QVector<IConstant*>&) const;

protected:
    /**
      Application de l'opérateur
      @return {IConstant*} result
    */
    virtual IConstant* exec(const QVector<IConstant*>&) const = 0;
    /** nombre d'arguments que prend l'opérateur */
    unsigned int _unarite;
    void fromString(const QString &);
    QVector<bool> _allowed_datas;
};

#endif // IOPERATEUR_H
