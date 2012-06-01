#ifndef ExpressionFactory_H
#define ExpressionFactory_H


#include <QString>
#include "include_all_expressions.h"


class ExpressionFactory
{
public:
    ExpressionFactory();
    /**
      Parse une string sans espace pour donne un IExpression
      @param {string} str
      @return {IExpression*}
    */
    IExpression* parse(const QString&);

private:
    QVector<IExpression*> _expressions;

};


#endif // ExpressionFactory_H
