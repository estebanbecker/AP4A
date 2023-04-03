#ifndef __LISTE_RECURSIF_H
#define __LISTE_RECURSIF_H
/*
 * Creer une classe liste generique (avec template)
 * avec une implentation en recursif.
 *
 * Auteur : JC. Creput
 * 20/03/2022
 */
#include <iostream>
#include <string>

using namespace std;

#define ITERATOR  1

// Classe liste
template <class T>
class Liste {
    T val; // tete de liste = element
    Liste* reste; // suivi d'une liste

public:
    // Forme canonique de Coplien (4 operations)
    // Cons. par defaut
    Liste() : reste(NULL) {} //liste vide, val est bidon

    // Cons. copie
    Liste(const Liste& l);

    // Destructeur
    ~Liste();

    // Affectation
    Liste& operator=(const Liste& l);

    // Modificateur
    T& operator[](int pos);

    // Longueur
    int longueur();

    // Ajout
    void ajouter(const T& val, int pos);

    // Suppression
    void supprimer(int pos);

    // Concatenation
    Liste concat(Liste& l);// utiliser l'autoConcat

    // Auto-concatenation
    Liste& autoConcat(Liste& l);

    // Entrees-sorties
    friend ostream& operator<<(ostream &o, Liste &l) {
        if (l.reste != NULL) {
        // en 2 lignes :
        // ...
        }
        return o;
    }

#if ITERATOR
    class Iterateur {
        friend class Liste;
        Liste<T>* pl;
        Iterateur(Liste* l) : pl(l) {}
    public:
        Iterateur();
        bool operator!=(Iterateur it);
        Iterateur& operator++();
        Iterateur operator++(int i);
        T& operator*() {// operateur de dereferencement *iter
            return pl->val;
        }
    };
    Iterateur begin() {
        Iterateur it(this);
        return it;
    }
    Iterateur end() {
        Iterateur it(NULL);
        return it;
    }
#endif
};


#endif //__LISTE_RECURSIF_H
