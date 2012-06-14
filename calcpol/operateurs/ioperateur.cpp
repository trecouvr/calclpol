#include "ioperateur.h"


IOperateur::IOperateur(int u, bool allow_entier, bool allow_reel, bool allow_rationnel, bool allow_complex) :
    IExpression(IExpression::OPERATOR),
    _unarite(u), _allowed_datas(QVector<bool>(4)) {
    _allowed_datas[IConstant::ENTIER]         = allow_entier;
    _allowed_datas[IConstant::REEL]           = allow_reel;
    _allowed_datas[IConstant::RATIONNEL]    = allow_rationnel;
    _allowed_datas[IConstant::COMPLEX]        = allow_complex;
}

IOperateur::~IOperateur() {}

unsigned int IOperateur::unarite() const {
    return _unarite;
}

IConstant* IOperateur::exec(unsigned int mode, const QVector<IConstant*>& args) const {
    if (mode > 3 or !_allowed_datas[mode]) {
        throw std::logic_error("L'operateur ne supporte pas ce type de données");
    }
    return this->exec(args);
}

void IOperateur::fromString(const QString &) {}
