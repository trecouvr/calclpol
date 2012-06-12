#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "deque"

#include "expressionfactory.h"
#include "cast.h"

/**
  Classe qui va manipuler des IExpression* pour faire des opérations en notation polonaise inversée.
*/
class Calculator
{
public:
    typedef std::deque<IExpression*>    Pile;
    typedef Pile::const_iterator    const_iterator;
	typedef Pile::const_reverse_iterator    const_reverse_iterator;
    Calculator();
    const_iterator begin() const;
    const_iterator end() const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
    /**
      Mettre une expression sur le dessus de la pile (sans l'évaluer).
    */
    void push(IExpression *);
    /**
      Inverser deux éléments de la pile, l'index commence à 0.
      @param {int} x
      @param {int} y
    */
    void swap(int x, int y);
    /**
      Supprimer de la pile les X premiers éléments.
      @param {int} x -1 pour toute la pile
    */
    void drop(int x);
    /**
      Ajouter à la pile une copie du premier élément.
    */
    void dup();
    /**
      Vider la pile.
    */
    void clear();
    /**
      Faire la somme des x premiers éléments.
      Si apply vaut true,
      alors la pile sera modifée, les x premiers éléments seront supprimé
      et resultat sera push.
      @param {int} x -1 pour toute la pile
      @param {bool} apply appliquer ou non le calcul à la pile
    */
    IConstant* sum(int x, bool apply=true);
    /**
      Faire la moyenne des x premiers éléments.
      Si apply vaut true,
      alors la pile sera modifée, les x premiers éléments seront supprimé
      et le resultat sera push.
      @param {int} x -1 pour toute la pile
      @param {bool} apply appliquer ou non le calcul à la pile
    */
    IConstant* mean(int x, bool apply);
    /**
      Retourne les X première valeurs de la pile casté en IConstant* du mode actuel,
      ou lance une exception.
      @param {int} x -1 pout toute la pile
      @param {bool} make_pop supprime les élément de la pile si tout le cast s'est bien passé
    */
    QVector<IConstant*> getCtes(int x=-1, bool make_pop=false);
    /**
      Evaluer une expression et faire les opérations necessaires sur la pile.
      @param {const QString&} expression
    */
    void eval(const QString & s);
    /**
      Evaluer une commande et faire les opérations necessaires sur la pile.
      @param {const QString&} expression
      @return {bool} si une commande a été trouvée
    */
    bool evalCmd(const QString & s);
    /**
      Appliquer une opérateur sur la pile
      @param {const IOperateur*} op
    */
    void applyOperator(const IOperateur * op);

    /**
      Caster une expression dans le mode courant du calculateur.
      @param {IExpression**} ptr_expression*
      @return {IExpression**} ptr_expression*
    */
    IExpression** castExp(IExpression **exp) const;
    /**
      Caster une expression dans le mode courant du calculateur.
      @param {IExpression**} ptr_expression*
      @return {IConstant**} ptr_expression*
    */
    IConstant** castExpToCte(IExpression **exp) const;
    /**
      Caster toute la pile
      @param {IConstant::T_CONSTANT} type de constante
      @param {int} limite -1 pour toute la pile
    */
    void castPile(IConstant::T_CONSTANT t, int limit=-1);
    /**
      Activer ou non le mode complex.
      @param {bool} actif
    */
    void complex(bool);
    void t_constant(IConstant::T_CONSTANT t);
    /**
      Renvoie une string représentant l'état actuel.
      @return {QString} state
    */
    QString stateToString() const;
    /**
      Charge l'état passé sous forme de string.
      @param {QString} state
    */
    void stateFromString(const QString&);

protected:
    /**
      Borner la valeur de x tq 0 <= x <= TAILLE_PILE
      @param {int} x -1 pour toute la pile
      @return {unsigned int} x_borne
    */
    unsigned int _limit(int x) const;
    Pile _pile;
    ExpressionFactory _factory;
    IConstant::T_CONSTANT _t_constant;
    bool _complex;
};

#endif // CALCULATOR_H
