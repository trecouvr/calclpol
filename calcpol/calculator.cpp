#include "calculator.h"
#include "logger.h"


#include <QStringList>

Calculator::Calculator() : _t_constant(IConstant::ENTIER), _complex(false) {
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
    IExpression * arg;
    // récupération des arguments sur la pile
    if (op->unarite() > _pile.size()) {
        throw 42;
    }
    for (unsigned int i=0; i<op->unarite(); ++i) {
        try {
            arg = _pile[i]->copy();
            this->castExp(&arg);
            args.push_back(dynamic_cast<IConstant*>(arg));
        }
        catch (std::exception& e) {
            for (QVector<IConstant*>::iterator it=args.begin(); it!=args.end(); ++it) {
                delete (*it);
            }
            throw e;
        }
    }
    // application de l'opérateur
    IConstant * result = op->exec(0,args);
    // si on a eu aucune erreur, on peut supprimer les arguments de la
    // pile et empiler le résultat
    for (unsigned int i=0; i<op->unarite(); ++i) {
        this->pop();
    }
    this->push(result);
}


IExpression** Calculator::castExp(IExpression ** pptr_exp) const {
    if (_complex)
        return Cast::castExp(IConstant::COMPLEX, pptr_exp, false, _t_constant);
    else
        return Cast::castExp(_t_constant, pptr_exp);
}

void Calculator::castPile(IConstant::T_CONSTANT t, int limit) {
    if (limit==-1) {
        limit = _pile.size();
    }
    else if (limit > _pile.size()) {
        limit = _pile.size();
    }
    for (unsigned int i=0; i<limit; ++i) {
        Cast::castExp(t, &_pile[i]);
    }
}

void Calculator::complex(bool b) {_complex = b;}
