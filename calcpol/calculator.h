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
      Caster le type de re et im d'un complex.
      @param {IConstant::T_CONSTANT} type
      @param {Complex**} pptr_cplx
      @return {Complex**} pptr_cplx
    */
    static Complex** castComplex(IConstant::T_CONSTANT t, Complex ** pptr_cplx);

    /**
      Caster une constante.
      Si la constante est déjà du bon type, rien ne se passe, sinon une nouvelle du bon type est créée,
      puis l'ancienne est détruite.
      Lorsque la fonction dois caster des constantes en complex, il y a le choix de garder le type courant,
      ou d'en imposer un.
      @param {IConstant::T_CONSTANT} type
      @param {IConstant**} pptr_cte
      @param {bool} cplx_keep garder le type courant ?
      @param {IConstant::T_CONSTANT} cplx_t imposition du type pour re et im des complex, cplx_keep dois être à true
      @return {IConstant**} pptr_cte
    */
    static IConstant** castCte(IConstant::T_CONSTANT t, IConstant ** pptr_cte, bool cplx_keep=true, IConstant::T_CONSTANT cplx_t=IConstant::ENTIER);
    /**
      Caster une expression
      Si l'expression n'est pas une constante, rien ne se passe.
      Sinon, une nouvelle du bon type est créer et l'ancienne expression est detruite
      @param {IConstant::T_CONSTANT} type de constante
      @param {IExpression**} ptr_expression*
      @param {bool} cplx_keep garder le type courant ?
      @param {IConstant::T_CONSTANT} cplx_t imposition du type pour re et im des complex, cplx_keep dois être à true
      @return {IExpression**} ptr_expression*
    */
    static IExpression** castExp(IConstant::T_CONSTANT t, IExpression ** exp, bool cplx_keep=true, IConstant::T_CONSTANT cplx_t=IConstant::ENTIER);
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
