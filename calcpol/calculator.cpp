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
        // si on a trouvé un opérateur, on l'applique imédiatement sur la pile
        if (IExpression::OPERATOR == exp->t()) {
            IOperateur * op = dynamic_cast<IOperateur*>(exp);
            this->applyOperator(op);
        }
        // si c'est une constante on l'empile
        else if (IExpression::CONSTANT == exp->t()) {
            this->push(exp);
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
