#include "ioperateur.h"


IOperateur::IOperateur(const QRegExp& re, int u, bool allow_entier, bool allow_reel, bool allow_rationnelle, bool allow_complex) :
    IExpression(IExpression::OPERATOR, re),
    _unarite(u), _allowed_datas(QVector<bool>(4)) {
    _allowed_datas[IDonnee::ENTIER]         = allow_entier;
    _allowed_datas[IDonnee::REEL]           = allow_reel;
    _allowed_datas[IDonnee::RATIONNELLE]    = allow_rationnelle;
    _allowed_datas[IDonnee::COMPLEX]        = allow_complex;
}

unsigned int IOperateur::unarite() const {
    return _unarite;
}


IDonnee* IOperateur::exec(unsigned int mode, IDonnee **args) {
    if (mode > 3 or !_allowed_datas[mode]) {
        throw 42;
    }
    return this->exec(args);
}


