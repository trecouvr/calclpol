#include "calculator.h"

Calculator::Calculator()
{
}

IDonnee* Calculator::pop()
{
	IDonnee* r = _pile[0];
	_pile.pop_front();
	return r;
}

void Calculator::swap(int x, int y)
{
	IDonnee* tmp;
	tmp = _pile[x];
	_pile[x] = _pile[y];
	_pile[y] = tmp;
}

void Calculator::drop()
{
	_pile.pop_front();
}

void Calculator::dup()
{
	IDonnee* data = _pile[0];
	IDonnee* datadup = data->copy();
	_pile.push_front(datadup);
}

void Calculator::clear()
{
	_pile.clear();
}

IDonnee* Calculator::sum(int x)
{
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
	IDonnee* a = sum(x);
	//return a / x;
	// TODO : En attendant la surchagre de l'opérateur /
	return a;
}
