#include "cast.h"

Cast::Cast()
{
}



Complex** Cast::castComplex(IConstant::T_CONSTANT t, Complex ** pptr_c) {
    if (t==IConstant::COMPLEX) {
        throw 42; // interdit de mettre des complex dans les complex
    }
    Complex * c = *pptr_c;
    // on regarde si ses parties imaginaire ou reel on besoin d'être casté
    if (c->re()->t_constant() != t or c->im()->t_constant() != t) {
        // copy
        IConstant * re = c->re()->copy();
        IConstant * im = c->im()->copy();
        // cast
        re = *Cast::castCte(t, &re);
        im = *Cast::castCte(t, &im);
        // assignation des nouvelles valeurs du bon type
        c->re(re);
        c->im(im);
        // destruction des copy
        delete re;
        delete im;
    }
    return pptr_c;
}

IConstant** Cast::castCte(IConstant::T_CONSTANT t, IConstant ** pptr_cte, bool cplx_keep, IConstant::T_CONSTANT cplx_t) {
    IConstant * cte = *pptr_cte;
    // si cast en complex
    // et déjà en complex
    // et on veut imposer un type à re et im
    if (!cplx_keep and cte->t_constant() == IConstant::COMPLEX and t == IConstant::COMPLEX) {
        Complex * ptr_cplx = dynamic_cast<Complex*>(cte);
        *pptr_cte = *Cast::castComplex(cplx_t, &ptr_cplx);
    }
    // sinon
    else if (cte->t_constant() != t) {
        IConstant * n = 0;
        switch (t) {
        case IConstant::REEL:
            n = new Reel(*cte);
            break;
        case IConstant::ENTIER:
            n = new Entier(*cte);
            break;
        case IConstant::RATIONNEL:
            n = new Rationnel(*cte);
            break;
        case IConstant::COMPLEX:
            // si on ne veut pas garder le type actuel
            if (!cplx_keep) {
                // on cast d'abbord dans le nouveau type voulue
                Cast::castCte(cplx_t, &cte);
                Cast::castCte(IConstant::COMPLEX, &cte);
                return &cte;
            }
            n = new Complex(*cte);
            break;
        }
        delete *pptr_cte;
        *pptr_cte = n;
    }
    return pptr_cte;
}

IExpression** Cast::castExp(IConstant::T_CONSTANT t, IExpression ** pptr_exp, bool cplx_keep, IConstant::T_CONSTANT cplx_t) {
    if ((*pptr_exp)->t_exp() == IExpression::CONSTANT) {
        IConstant * p_cte = dynamic_cast<IConstant*>(*pptr_exp);
        *pptr_exp = *Cast::castCte(t,&p_cte,cplx_keep,cplx_t);
    }
    return pptr_exp;
}


