#ifndef ICONSTANT_H
#define ICONSTANT_H


#include "iexpression.h"
#include "logger.h"

/**
  Meta classe des constantes.
  Elle définie les opérations applicables à une constante qui devront être surchargées
  si elles sont virtual pur, par default les opérations lancent une exception.
*/
class IConstant : public IExpression
{
public:
    enum T_CONSTANT {ENTIER, REEL, RATIONNEL, COMPLEX};
    IConstant(T_CONSTANT t);
    virtual ~IConstant();
    T_CONSTANT t_constant() const;
    virtual operator long() const = 0;
    virtual operator double() const = 0;
    virtual IConstant& operator+=(const IConstant&) = 0;
    virtual IConstant& operator-=(const IConstant&) = 0;
    virtual IConstant& operator/=(const IConstant&) = 0;
    virtual IConstant& operator*=(const IConstant&) = 0;
    virtual IConstant& operator/=(int) = 0;
    /**
      Créer une copie du même type.
      @return {IConstant*} copy
    */
    virtual IConstant* copy() const = 0;
    /**
      Créer une copie du même type, et l'initialise à partir d'un double.
      @return {IConstant*} copy
    */
    virtual IConstant* copy(double) const = 0;

protected:
    T_CONSTANT _t_constant;
};


#endif // ICONSTANT_H
