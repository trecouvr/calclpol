#include "expressionfactory.h"


ExpressionFactory::ExpressionFactory() {
    _expressions.push_back(new OperateurMinus());
    _expressions.push_back(new OperateurPlus());
    _expressions.push_back(new OperateurSinus());
    _expressions.push_back(new OperateurCosinus());
    _expressions.push_back(new OperateurTangente());
	_expressions.push_back(new OperateurFactorielle());
	_expressions.push_back(new OperateurSinh());
	_expressions.push_back(new OperateurCosh());
	_expressions.push_back(new OperateurTanh());
	_expressions.push_back(new OperateurLn());
	_expressions.push_back(new OperateurLog());
	_expressions.push_back(new OperateurInv());
	_expressions.push_back(new OperateurSqrt());
	_expressions.push_back(new OperateurSqr());
	_expressions.push_back(new OperateurCube());

    _expressions.push_back(new Entier());
    _expressions.push_back(new Reel());
    _expressions.push_back(new Complex());
}

IExpression* ExpressionFactory::parse(const QString& s) {
    for (QVector<IExpression*>::const_iterator it=_expressions.begin(); it!=_expressions.end(); ++it) {
        IExpression * exp = *it;
        if (exp->regexp().exactMatch(s)) {
            IExpression * r = exp->copy();
            r->fromString(s);
            return r;
        }
    }
    return 0;
}


