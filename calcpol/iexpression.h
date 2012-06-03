#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <QString>
#include <QRegExp>

#include <exception>

/**
  Class générique représentant une donnée de la pile
*/
class IExpression
{
public:
    enum T_EXP {CONSTANT, OPERATOR, EXPRESSION};
    explicit IExpression(T_EXP t);
    /**
      Créer une copie du même type
      @return {IExpression*} copy
    */
    virtual IExpression* copy() const = 0;
    /**
      Retourne le type de l'expression
      @return {IExpression::T_EXP} type
    */
    IExpression::T_EXP t_exp() const;
    /**
      Fonction appellée lors de l'affichage.
      @return {QString} visuel de l'expression
    */
    virtual QString toString() const = 0;
    /**
      Fonction appellée lors de l'initialisation à partir d'une string,
      la fonction doit parser un string et mettre à jour l'objet.
      @param {const QString&}
    */
    virtual void fromString(const QString&);
    /**
      Retourne la regexp permettant d'identifier l'expression.
      @return {QRegExp} re
    */
    virtual QRegExp regexp() const = 0;

protected:
    T_EXP _t_exp;
};

#endif // IEXPRESSION_H
