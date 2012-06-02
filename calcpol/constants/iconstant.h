#ifndef ICONSTANT_H
#define ICONSTANT_H


#include "iexpression.h"

/**
  Meta classe des constantes.
  Elle définie les opérations applicables à une constante qui devront être surchargées
  si elles sont virtual pur, par default les opérations lancent une exception.
*/
class IConstant : public IExpression
{
public:
    enum T_CONSTANT {ENTIER, REEL, RATIONNELLE, COMPLEX};
    IConstant(T_CONSTANT t);
    T_CONSTANT t_constant() const;
    virtual operator long() const = 0;
    virtual operator double() const = 0;
    virtual IConstant& operator+=(const IConstant&) = 0;
    virtual IConstant& operator-=(const IConstant&) = 0;
    virtual IConstant& operator/=(const IConstant&) = 0;
    /**
      Créer une copie du même type
      @return {IConstant*} copy
    */
    virtual IConstant* copy() const = 0;
    /**
      Additionner avec une autre constante dans un nouvel objet
      @param {const IConstant*} other
      @return IConstant* result
    */
    virtual IConstant* plus(const IConstant*) const = 0;
    /**
      Soustraire avec une autre constante dans un nouvel objet
      @param {const IConstant*} other
      @return IConstant* result
    */
    virtual IConstant* minus(const IConstant*) const = 0;
    /**
      Multiplier avec une autre constante dans un nouvel objet
      @param {const IConstant*} other
      @return IConstant* result
    */
    //virtual IDonnee* multiply(const IDonnee*) const = 0;
    /**
      Diviser avec une autre constante dans un nouvel objet
      @param {const IConstant*} other
      @return IConstant* result
    */
    //virtual IDonnee* div(const IDonnee*) const = 0;
    /**
      Calculer le sinus dans un nouvel objet
      @param {bool} rad mode radian
      @return IConstant* result
    */
    virtual IConstant* sinus(bool rad=true) const;
    /**
      Calculer le cosinus dans un nouvel objet
      @param {bool} rad mode radian
      @return IConstant* result
    */
    virtual IConstant* cosinus(bool rad=true) const;
    /**
      Calculer la tangente dans un nouvel objet
      @param {bool} rad mode radian
      @return IConstant* result
    */
    virtual IConstant* tangente(bool rad=true) const;

protected:
    T_CONSTANT _t_constant;
};


#endif // ICONSTANT_H
