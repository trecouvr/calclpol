#include "expressionfactory.h"


ExpressionFactory* ExpressionFactory::_ptr=0;

ExpressionFactory::ExpressionFactory() {}

ExpressionFactory* ExpressionFactory::get() {
    if (ExpressionFactory::_ptr == 0) {
        ExpressionFactory::_ptr = new ExpressionFactory();
    }

    return ExpressionFactory::_ptr;
}


IExpression* ExpressionFactory::_parse(const QString& s) const {
    if ("+" == s) {
        return new OperateurPlus();
    }
    else if ("-" == s) {
        return new OperateurMinus();
    }

    throw 42;
}


