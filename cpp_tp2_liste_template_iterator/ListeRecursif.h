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

#define ITERATOR  0

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
    Liste(const Liste& l){
        if (l.reste != NULL) {
            val = l.val;
            reste = new Liste(*l.reste);
        } else {
            reste = NULL;
        }
    };

    // Destructeur
    ~Liste(){
        if (reste != NULL) {
            delete reste;
        }
    };

    // Affectation
    Liste& operator=(const Liste& l){
        if (this != &l) {
            val = l.val;
            if (l.reste != NULL) {
                reste = new Liste(*l.reste);
            } else {
                reste = NULL;
            }
        }
        return *this;
    };

    // Modificateur
    T& operator[](int pos){
        if (pos == 0) {
            return val;
        } else {
            return (*reste)[pos-1];
        }
    };

    // Longueur
    int longueur(){
        if (reste == NULL) {
            return 0;
        } else {
            return 1 + reste->longueur();
        }
    };

    // Ajout
    void ajouter(const T& new_val, int pos){
        if (pos == 0) {
            Liste* l = new Liste(*this);
            this->val = new_val;
            reste = l;
        } else {
            if(reste == NULL) {
                this->val = new_val;
                reste = new Liste();
            }else{
                reste->ajouter(new_val, pos-1);
            }
        }
    };

    // Suppression
    // Si la valeur est élevée, on ne supprime pas
    void supprimer(int pos){
        if (pos == 0) {
            Liste* l = reste->reste;
            reste->reste = NULL;
            this->val = reste->val;
            delete reste;
            reste = l;
        } else {
            if (reste != NULL) {
                if(reste->reste == NULL){
                    delete reste;
                    reste = NULL;
                }else{
                    reste->supprimer(pos-1);
                }
                
            }

        }
    };

    // Concatenation
    Liste concat(Liste& l){
        Liste* l1 = new Liste(*this);
        Liste* l2 = new Liste(l);
        l1->autoConcat(*l2);
        return *l1;
    };// utiliser l'autoConcat

    // Auto-concatenation
    Liste& autoConcat(Liste& l){
        if (reste == NULL) {
            reste = new Liste(l);
        } else if (reste->reste == NULL) {
            reste = new Liste(l);
        } else {
            reste->autoConcat(l);
        }
        return *this;
    };

    // Entrees-sorties
    friend ostream& operator<<(ostream &o, Liste &l) {
        if(l.reste == NULL) {
            o << " ";
            return o;
        }
        else if (l.reste->reste != NULL) {
            o << l.val << " ";
            o << *l.reste;
        } else {
            o << l.val;
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
