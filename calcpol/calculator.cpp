#include "calculator.h"
#include "logger.h"


#include <QStringList>

Calculator::Calculator() : _t_constant(IConstant::ENTIER), _complex(false) {
    Logger::i("Calculator","Constructeur");
}


void Calculator::push(IExpression * exp)
{
    Logger::v("Calculator","push()");
    _pile.push_front(exp);
}

void Calculator::swap(int x, int y) {
    Logger::v("Calculator","swap()");
    x = min((int)_pile.size()-1, max(0, x));
    y = min((int)_pile.size()-1, max(0, y));
    IExpression* tmp;
    tmp = _pile[x];
    _pile[x] = _pile[y];
    _pile[y] = tmp;
}

void Calculator::drop(int x) {
    Logger::v("Calculator","drop()");
    unsigned int limit = this->_limit(x);
    for (unsigned int i=0; i<limit; ++i)
        _pile.pop_front();
}

void Calculator::dup()
{
    Logger::v("Calculator","dup()");
    IExpression* data = _pile[0];
    IExpression* datadup = data->copy();
    this->push(datadup);
}

void Calculator::clear() {
    Logger::v("Calculator","clear()");
    _pile.clear();
}

IConstant* Calculator::sum(int x, bool apply) {
    Logger::v("Calculator","sum()");
    unsigned int limit = this->_limit(x);
    if (limit>0) {
        QVector<IConstant*> values = this->getCtes(limit, false);
        QVector<IConstant*>::iterator it = values.begin();
        IConstant* result = *it;
        ++it;
        for (; it!= values.end(); ++it) {
            *result += *(*it);
        }

        result = result->copy();

        // suppression des copy
        for(it = values.begin(); it!= values.end(); ++it) {
            delete *it;
        }

        if (apply) {
            // suppression des valeurs de la pile
            this->drop(limit);
            // empilage du résultat
            this->push(result);
        }

        return result;
    }
    else {
        return 0;
    }
}

IConstant* Calculator::mean(int x, bool apply) {
    Logger::v("Calculator","mean()");
    unsigned int limit = this->_limit(x);
    if (limit>0) {
        IConstant* a = sum(limit,false);
        *a /= x;
        if (apply) {
            this->drop(limit);
            this->push(a);
        }
        return a;
    }
    else {
        return 0;
    }
}

Calculator::const_iterator Calculator::begin() const {
    return _pile.begin();
}

Calculator::const_iterator Calculator::end() const {
    return _pile.end();
}

bool Calculator::evalCmd(const QString &s) {
    const QRegExp
            re_mean("mean(-?\\d+)"),
            re_sum("sum(-?\\d+)"),
            re_dup("dup"),
            re_swap("swap(\\d+)_(\\d+)"),
            re_setmode("setmode_(\\w+)"),
            re_complex("(no)?complexmode");
    // moyenne
    if (re_mean.exactMatch(s)) {
        QStringList l = re_mean.capturedTexts();
        this->mean(l[1].toInt(),true);
        return true;
    }
    // somme
    else if (re_sum.exactMatch(s)) {
        QStringList l = re_sum.capturedTexts();
        this->sum(l[1].toInt(),true);
        return true;
    }
    // duplication
    else if (re_dup.exactMatch(s)) {
        this->dup();
        return true;
    }
    // swap
    else if (re_swap.exactMatch(s)) {
        QStringList l = re_swap.capturedTexts();
        this->swap(l[1].toInt(), l[2].toInt());
        return true;
    }
    // setmode
    else if (re_setmode.exactMatch(s)) {
        QStringList l = re_setmode.capturedTexts();
        if (l[1] == "entier") {
            _t_constant = IConstant::ENTIER;
            return true;
        }
        else if (l[1] == "reel") {
            _t_constant = IConstant::REEL;
            return true;
        }
        else if (l[1] == "rationnel") {
            _t_constant = IConstant::RATIONNELLE;
            return true;
        }
    }
    // swap
    else if (re_complex.exactMatch(s)) {
        QStringList l = re_complex.capturedTexts();
        if (l[1] == "no") { // "no"
            _complex = false;
        }
        else {
            _complex = true;
        }
        return true;
    }

    return false;
}

void Calculator::eval(const QString &s) {
    // split de l'input
    QStringList list = s.split(' ', QString::SkipEmptyParts);
    // itération sur les différentes expressions
    for (QStringList::iterator it=list.begin(); it != list.end(); ++it) {
        // génération de la bonne classe fille IExpression grâce à la factory
        IExpression * exp = _factory.parse(*it);
        // si la factory n'a pas réussi à parser alors c'est peut être une commande
        if (exp==0) {
            if (!this->evalCmd(s)) {
                // bah c'est rien de connu !
                Logger::w("Calculator", "eval, l'input n'a pas pu être parsé, input="+s);
            }
        }
        else {
            IOperateur * op;
            switch (exp->t_exp()) {
            // si on a trouvé un opérateur, on l'applique imédiatement sur la pile
            case IExpression::OPERATOR:
                op = dynamic_cast<IOperateur*>(exp);
                this->applyOperator(op);
                break;
            // si c'est une constante on l'empile
            case IExpression::CONSTANT:
                this->push(exp);
                break;
            default:
                throw 42;
                break;
            }
        }
    }
}

QVector<IConstant*> Calculator::getCtes(int x, bool make_pop) {
    QVector<IConstant*> args;
    IConstant * arg;
    unsigned int limit = this->_limit(x);

    for (unsigned int i=0; i<limit; ++i) {
        IExpression * exp = _pile[i]->copy();
        try {
            arg = *(this->castExpToCte(&exp));
        }
        catch (std::exception& e) {
            for (QVector<IConstant*>::iterator it=args.begin(); it!=args.end(); ++it) {
                delete (*it);
            }
            throw e;
        }
        args.push_back(arg);
    }

    if (make_pop) {
        this->drop(limit);
    }

    return args;
}

void Calculator::applyOperator(const IOperateur * op) {
    // récupération des arguments sur la pile
    if (op->unarite() > _pile.size()) {
        throw 42;
    }
    // récupérer les X première valeurs sans les supprimer de la pile
    QVector<IConstant*> args = this->getCtes(op->unarite(), false);
    // application de l'opérateur
    IConstant * result = op->exec(0,args);
    // si on a eu aucune erreur, on peut supprimer les arguments de la
    // pile et empiler le résultat
    this->drop(op->unarite());
    this->push(result);
}


IExpression** Calculator::castExp(IExpression ** pptr_exp) const {
    if (_complex)
        return Cast::castExp(IConstant::COMPLEX, pptr_exp, false, _t_constant);
    else
        return Cast::castExp(_t_constant, pptr_exp);
}

IConstant** Calculator::castExpToCte(IExpression ** pptr_exp) const {
    this->castExp(pptr_exp);
    IConstant * r = dynamic_cast<IConstant*>(*pptr_exp);
    return new (IConstant*)(r);
}

void Calculator::castPile(IConstant::T_CONSTANT t, int limit) {
    if (limit<0) {
        limit = _pile.size();
    }
    else if (limit > (int)_pile.size()) {
        limit = (int)_pile.size();
    }
    for (int i=0; i<limit; ++i) {
        Cast::castExp(t, &_pile[i]);
    }
}

void Calculator::complex(bool b) {_complex = b;}

unsigned int Calculator::_limit(int x) const {
    unsigned int limit=0;
    // x<0 ou pile plus petite que x => prendre toute la pile
    if (x<0 or x>(int)_pile.size()) {
        limit = _pile.size();
    }
    else {
        limit = x;
    }

    return limit;
}
