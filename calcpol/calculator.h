#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "deque"
using std::deque;

#include "include_all_donnees.h"

class Calculator
{
public:
    Calculator();
protected:
    deque<IDonnee*> _pile;
};

#endif // CALCULATOR_H
