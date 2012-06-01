#include "expressionfactory.h"


ExpressionFactory::ExpressionFactory() {
    _expressions.push_back(new OperateurMinus());
    _expressions.push_back(new OperateurPlus());
    _expressions.push_back(new OperateurSinus());
    _expressions.push_back(new Entier());
    _expressions.push_back(new Reel());
    _expressions.push_back(new Complex());
}

IExpression* ExpressionFactory::parse(const QString& s) {
    for (QVector<IExpression*>::const_iterator it=_expressions.begin(); it!=_expressions.end(); ++it) {
        IExpression * exp = *it;
        if (s.contains(exp->regexp())) {
            IExpression * r = exp->copy();
            r->fromString(s);
            return r;
        }
    }
    return 0;
}


