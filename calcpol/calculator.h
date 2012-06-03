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
    void drop();
    void dup();
    void clear();
    IConstant* sum(int x);
    IConstant* mean(int x);
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
    IExpression* pop();
    void push(IExpression *);
    Pile _pile;
    ExpressionFactory _factory;
    IConstant::T_CONSTANT _t_constant;
    bool _complex;
};

#endif // CALCULATOR_H
