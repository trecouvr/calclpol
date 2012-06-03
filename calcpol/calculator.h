#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "deque"

#include "expressionfactory.h"
#include "cast.h"

/**
  Classe qui va manipuler des IExpression* pour faire des opérations en notation polonaise inversée.
*/
class Calculator
{
public:
    typedef std::deque<IExpression*>    Pile;
    typedef Pile::const_iterator    const_iterator;
    Calculator();
    const_iterator begin() const;
    const_iterator end() const;
    void swap(int x, int y);
    void drop(int x);
    void dup();
    void clear();
    IConstant* sum(int x, bool apply=true);
    IConstant* mean(int x, bool apply);
    /**
      Retourne les X première valeurs de la pile casté en IConstant* du mode actuel,
      ou lance une exception.
      @param {int} x -1 pout toute la pile
      @param {bool} make_pop supprime les élément de la pile si tout le cast s'est bien passé
    */
    QVector<IConstant*> getCtes(int x=-1, bool make_pop=false);
    /**
      Evaluer une expression et faire les opérations necessaires sur la pile.
      @param {const QString&} expression
    */
    void eval(const QString & s);
    /**
      Appliquer une opérateur sur la pile
      @param {const IOperateur*} op
    */
    void applyOperator(const IOperateur * op);

    /**
      Caster une expression dans le mode courant du calculateur.
      @param {IExpression**} ptr_expression*
      @return {IExpression**} ptr_expression*
    */
    IExpression** castExp(IExpression **exp) const;
    /**
      Caster une expression dans le mode courant du calculateur.
      @param {IExpression**} ptr_expression*
      @return {IConstant**} ptr_expression*
    */
    IConstant** castExpToCte(IExpression **exp) const;
    /**
      Caster toute la pile
      @param {IConstant::T_CONSTANT} type de constante
      @param {int} limite -1 pour toute la pile
    */
    void castPile(IConstant::T_CONSTANT t, int limit=-1);
    /**
      Activer ou non le mode complex.
      @param {bool} actif
    */
    void complex(bool);

protected:
    unsigned int _limit(int x) const;
    IExpression* pop();
    void push(IExpression *);
    Pile _pile;
    ExpressionFactory _factory;
    IConstant::T_CONSTANT _t_constant;
    bool _complex;
};

#endif // CALCULATOR_H
