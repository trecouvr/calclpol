#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "deque"
using std::deque;

#include "include_all_donnees.h"

class Calculator
{
public:
    Calculator();
	IDonnee* pop();
	void swap(int x, int y);
	void drop();
	void dup();
	void clear();
	IDonnee* sum(int x);
	IDonnee* mean(int x);

protected:
    deque<IDonnee*> _pile;
};

#endif // CALCULATOR_H
