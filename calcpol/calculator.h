#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "deque"

#include "include_all_donnees.h"

class Calculator
{
public:
    Calculator();
protected:
    std::deque<IDonnee*> _pile;
};

#endif // CALCULATOR_H
