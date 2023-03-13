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
class vecteur
{
private:

    int *tab;
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
    int& operator[](int);

    // affectation : =(vecteur), =(int)
    vecteur& operator=(const vecteur&);
    vecteur& operator=(int);

    // incrementation/decr. : ++(void), ++(int), --(void)
    vecteur& operator++(void);
    vecteur operator++(int);
    vecteur& operator--(void);

    // op. booleens : ==(vecteur&), <, >, <=, >=
    bool operator==(vecteur&);
    bool operator<(vecteur&);
    bool operator>(vecteur&);
    bool operator<=(vecteur&);
    bool operator>=(vecteur&);

    // op. binaires : +(vecteur&), -
    vecteur operator+(const vecteur&);
    vecteur operator-(const vecteur&);

    // produit scalaire: *(vecteur&)
    vecteur operator*(vecteur&);

    // produit par un scalaire: v * n, n * v
    vecteur operator*(int);
    friend vecteur operator*(int, vecteur&);

    // auto-adition : +=(vecteur&), -=
    vecteur& operator+=(vecteur&);
    vecteur& operator-=(vecteur&);

    // Operateurs d'entree/sortie: <<, >>
    friend ostream& operator<< (ostream&, vecteur&);
    friend istream& operator>> (istream&, vecteur&);

};

#endif // VECTEUR_H
