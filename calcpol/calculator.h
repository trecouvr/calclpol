#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "deque"

#include "expressionfactory.h"

class Calculator
{
public:
    typedef std::deque<IExpression*>    Pile;
    typedef Pile::const_iterator    const_iterator;
    Calculator();
    const_iterator begin() const;
    const_iterator end() const;
    void swap(int x, int y);
    void drop();
    void dup();
    void clear();
    IDonnee* sum(int x);
    IDonnee* mean(int x);
    void eval(const QString & s);
    void applyOperator(const IOperateur * op);

protected:
    IExpression* pop();
    void push(IExpression *);
    Pile _pile;
    ExpressionFactory _factory;
};

#endif // CALCULATOR_H
