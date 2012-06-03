#include "calculator.h"
#include "logger.h"


#include <QStringList>

Calculator::Calculator()
{
	Logger::i("Calculator","Constructeur");
}

IExpression* Calculator::pop()
{
	Logger::v("Calculator","pop()");
        IExpression* r = _pile[0];
	_pile.pop_front();
	return r;
}

void Calculator::push(IExpression * exp)
{
        Logger::v("Calculator","push()");
        _pile.push_front(exp);
}

void Calculator::swap(int x, int y)
{
	Logger::v("Calculator","swap()");
        IExpression* tmp;
	tmp = _pile[x];
	_pile[x] = _pile[y];
	_pile[y] = tmp;
}

void Calculator::drop()
{
	Logger::v("Calculator","drop()");
	_pile.pop_front();
}

void Calculator::dup()
{
        /*Logger::v("Calculator","dup()");
	IDonnee* data = _pile[0];
	IDonnee* datadup = data->copy();
        _pile.push_front(datadup);*/
}

void Calculator::clear()
{
	Logger::v("Calculator","clear()");
	_pile.clear();
}

IConstant* Calculator::sum(int x)
{
        /*Logger::v("Calculator","sum()");
	IDonnee* result = _pile[0]->copy();
	for(int _i=1; _i<x; _i++)
	{
		// TODO : En attente de l'opérateur += sur les IDonnee....
		//result += *(_pile[_i]);
	}
        return result;*/
    return 0;
}

IConstant* Calculator::mean(int x)
{
	Logger::v("Calculator","mean()");
	IConstant* a = sum(x);
	//return a / x;
	// TODO : En attendant la surchagre de l'opérateur /
	return a;
}

Calculator::const_iterator Calculator::begin() const {
    return _pile.begin();
}

Calculator::const_iterator Calculator::end() const {
    return _pile.end();
}

void Calculator::eval(const QString &s) {
    // split de l'input
    QStringList list = s.split(' ', QString::SkipEmptyParts);
    // itération sur les différentes expressions
    for (QStringList::iterator it=list.begin(); it != list.end(); ++it) {
        // génération de la bonne classe fille IExpression grâce à la factory
        IExpression * exp = _factory.parse(*it);
        // si la factory n'a pas réussi à parser alors on lance une exception
        if (exp==0) {
            throw 42;
        }
        IOperateur * op;
        switch (exp->t_exp()) {
        // si on a trouvé un opérateur, on l'applique imédiatement sur la pile
        case IExpression::OPERATOR:
            op = dynamic_cast<IOperateur*>(exp);
            this->applyOperator(op);
            break;
        // si c'est une constante on l'empile
        case IExpression::CONSTANT:
            this->push(exp);
            break;
        default:
            throw 42;
            break;
        }
    }
}

void Calculator::applyOperator(const IOperateur * op) {
    QVector<IConstant*> args;
    // récupération des arguments sur la pile
    for (unsigned int i=0; i<op->unarite(); ++i) {
        args.push_back(dynamic_cast<IConstant*>(this->pop()));
    }
    // application de l'opérateur
    IConstant * result = op->exec(0,args);
    // empilage du résultat
    this->push(result);
}

Complex** Calculator::castComplex(IConstant::T_CONSTANT t, Complex ** pptr_c) {
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
        re = *Calculator::castCte(t, &re);
        im = *Calculator::castCte(t, &im);
        // assignation des nouvelles valeurs du bon type
        c->re(re);
        c->im(im);
        // destruction des copy
        delete re;
        delete im;
    }
    return pptr_c;
}

IConstant** Calculator::castCte(IConstant::T_CONSTANT t, IConstant ** pptr_cte, bool cplx_keep, IConstant::T_CONSTANT cplx_t) {
    IConstant * cte = *pptr_cte;
    // si cast en complex
    // et déjà en complex
    // et on veut imposer un type à re et im
    if (!cplx_keep and cte->t_constant() == IConstant::COMPLEX and t == IConstant::COMPLEX) {
        Complex * ptr_cplx = dynamic_cast<Complex*>(cte);
        *pptr_cte = *Calculator::castComplex(cplx_t, &ptr_cplx);
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
        case IConstant::RATIONNELLE:
            n = new Rationnel(*cte);
            break;
        case IConstant::COMPLEX:
            // si on ne veut pas garder le type actuel
            if (!cplx_keep) {
                // on cast d'abbord dans le nouveau type voulue
                cte = *Calculator::castCte(cplx_t, &cte);
            }
            n = new Complex(*cte);
            break;
        }
        delete *pptr_cte;
        *pptr_cte = n;
    }
    return pptr_cte;
}

IExpression** Calculator::castExp(IConstant::T_CONSTANT t, IExpression ** pptr_exp, bool cplx_keep, IConstant::T_CONSTANT cplx_t) {
    if ((*pptr_exp)->t_exp() == IExpression::CONSTANT) {
        IConstant * p_cte = dynamic_cast<IConstant*>(*pptr_exp);
        *pptr_exp = *Calculator::castCte(t,&p_cte,cplx_keep,cplx_t);
    }
    return pptr_exp;
}


IExpression** Calculator::castExp(IExpression ** pptr_exp) const {
    if (_complex)
        return Calculator::castExp(IConstant::COMPLEX, pptr_exp, false, _t_constant);
    else
        return Calculator::castExp(_t_constant, pptr_exp);
}

void Calculator::castPile(IConstant::T_CONSTANT t, int limit) {
    if (limit==-1) {
        limit = _pile.size();
    }
    else if (limit > _pile.size()) {
        limit = _pile.size();
    }
    for (unsigned int i=0; i<limit; ++i) {
        Calculator::castExp(t, &_pile[i]);
    }
}

void Calculator::complex(bool b) {_complex = b;}
