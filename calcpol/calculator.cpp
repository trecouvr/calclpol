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

IDonnee* Calculator::sum(int x)
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

IDonnee* Calculator::mean(int x)
{
	Logger::v("Calculator","mean()");
	IDonnee* a = sum(x);
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
    QStringList list = s.split(' ', QString::SkipEmptyParts);
    for (QStringList::iterator it=list.begin(); it != list.end(); ++it) {
        IExpression * exp = _factory.parse(*it);
        if (exp==0) {
            throw 42;
        }
        if (IExpression::OPERATOR == exp->t()) {
            IOperateur * op = dynamic_cast<IOperateur*>(exp);
            this->applyOperator(op);
        }
        else if (IExpression::CONSTANT == exp->t()) {
            this->push(exp);
        }
    }
}

void Calculator::applyOperator(const IOperateur * op) {
    QVector<IDonnee*> args;
    for (unsigned int i=0; i<op->unarite(); ++i) {
        args.push_back(dynamic_cast<IDonnee*>(this->pop()));
    }
    IDonnee * result = op->exec(0,args);
    this->push(result);
}
