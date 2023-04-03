#ifndef VECTEUR_H
#define VECTEUR_H
//
// Type vecteur
//
#include <iostream>

using namespace std;
 
//
// Type vecteur de int
//
template <typename T> 
class Vecteur
{
private:

    T *tab;
    int taille;

public:

    // Constructeurs par defaut(void) , avec la taille du vect.(int), par copie(vecteur&)
    vecteur(void);
    vecteur(int);
    vecteur(vecteur&);

    // Destructeur
    ~vecteur();

    // Acces a la taille du vecteur
    int longueur();

    // acces au element []
    T& operator[](int);

    // affectation : =(vecteur), =(int)
    vecteur& operator=(const vecteur&);
    vecteur& operator=(T);

    // incrementation/decr. : ++(void), ++(int), --(void)
    vecteur& operator++(void);
    vecteur operator++(int);
    vecteur& operator--(void);

    // op. booleens : ==(vecteur&), <, >, <=, >=
    int operator==(vecteur&);
    int operator<(vecteur&);
    int operator>(vecteur&);
    int operator<=(vecteur&);
    int operator>=(vecteur&);

    // op. binaires : +(vecteur&), -
    vecteur operator+(const vecteur&);
    vecteur operator-(const vecteur&);

    // produit scalaire: *(vecteur&)
    vecteur operator*(vecteur&);

    // produit par un scalaire: v * n, n * v
    vecteur operator*(T);
    friend vecteur operator*(T, vecteur&);

    // auto-adition : +=(vecteur&), -=
    vecteur& operator+=(vecteur&);
    vecteur& operator-=(vecteur&);

    // Operateurs d'entree/sortie: <<, >>
    friend ostream& operator<< (ostream&, vecteur&);
    friend istream& operator>> (istream&, vecteur&);

};

#endif // VECTEUR_H
