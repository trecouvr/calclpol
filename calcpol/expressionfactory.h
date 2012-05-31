#ifndef ExpressionFactory_H
#define ExpressionFactory_H


#include <QString>
#include "include_all_expressions.h"


class ExpressionFactory
{
public:
    static ExpressionFactory * get();

    /**
      Parse une string sans espace pour donne un IExpression
      @param {string} str
      @return {IExpression*}
    */
    IExpression* parse(const QString&) const;

private:
    ExpressionFactory();
    static ExpressionFactory* _ptr;
};


#endif // ExpressionFactory_H
