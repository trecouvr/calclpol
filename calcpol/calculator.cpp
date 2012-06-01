#include "calculator.h"
#include "logger.h"

Calculator::Calculator()
{
	Logger::i("Calculator","Constructeur");
}

IDonnee* Calculator::pop()
{
	Logger::v("Calculator","pop()");
	IDonnee* r = _pile[0];
	_pile.pop_front();
	return r;
}

void Calculator::swap(int x, int y)
{
	Logger::v("Calculator","swap()");
	IDonnee* tmp;
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
	Logger::v("Calculator","dup()");
	IDonnee* data = _pile[0];
	IDonnee* datadup = data->copy();
	_pile.push_front(datadup);
}

void Calculator::clear()
{
	Logger::v("Calculator","clear()");
	_pile.clear();
}

IDonnee* Calculator::sum(int x)
{
	Logger::v("Calculator","sum()");
	IDonnee* result = _pile[0]->copy();
	for(int _i=1; _i<x; _i++)
	{
		// TODO : En attente de l'opérateur += sur les IDonnee....
		//result += *(_pile[_i]);
	}
	return result;
}

IDonnee* Calculator::mean(int x)
{
	Logger::v("Calculator","mean()");
	IDonnee* a = sum(x);
	//return a / x;
	// TODO : En attendant la surchagre de l'opérateur /
	return a;
}
