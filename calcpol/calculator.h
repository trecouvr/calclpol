#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "deque"

#include "expressionfactory.h"

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
      Caster une expression
      Si l'expression n'est pas une constante, rien ne se passe.
      Sinon, une nouvelle du bon type est créer et l'ancienne expression est detruite
    */
    static IExpression** cast_exp(IConstant::T_CONSTANT t, IExpression ** exp);
    /**
      Caster toute la pile
    */
    void cast_pile(IConstant::T_CONSTANT t);

protected:
    IExpression* pop();
    void push(IExpression *);
    Pile _pile;
    ExpressionFactory _factory;
};

#endif // CALCULATOR_H
