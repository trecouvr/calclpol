#ifndef CAST_H
#define CAST_H

#include "constants/constants.h"

class Cast
{
public:
    Cast();
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

};

#endif // CAST_H
