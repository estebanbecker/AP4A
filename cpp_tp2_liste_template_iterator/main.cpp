#include <iostream>

#include "ListeRecursif.h"

using namespace std;

int main()
{
    cout << "Test de la classe liste" << endl;

    Liste<int> l1;// liste de integer constr. par defaut
    Liste<float> lf;// liste de float
    // Liste<Camion*> lc;// si classe Camion existe

    // Operations sur la liste
    // Ajouter des elements a une position donnee
    int i = 3;
    l1.ajouter(3, 0);// ajouter
    i = 4;
    l1.ajouter(i, 0);
    i = 5;
    l1.ajouter(i, 0);
    i = 6;
    l1.ajouter(i, l1.longueur()+10);//longeur
    i = 7;
    l1.ajouter(i, 1);

    l1.ajouter(5, 0);

    cout << "liste l1 " << l1 << endl;// <<

    // Suppression d'element
    l1.supprimer(2); // suppression à une position donnee

    cout << "liste l1 " << l1 << endl;// <<

    l1.supprimer(l1.longueur()-1); // suppression à une position donnee

    cout << "liste l1 " << l1 << endl;// <<

    l1.supprimer(l1.longueur()); // suppression à une position donnee

    cout << "liste l1 " << l1 << endl;// <<

    // Longeur
    int ll = l1.longueur();
    cout << "longeur " << ll << endl;

    // Cons par copie
    Liste<int> l2 = l1;

    Liste<int> l3;
    // Affectation
    l3 = l2;

    cout << "liste l3 " << l3 << endl;

    // modifier un element a une position donnee
    l3[2] = 8;

    // Lire un element a une position donnee
    int elt = l3[1];

    cout << "element " << elt << endl;

    cout << "l1 : " << l1 << endl;
    cout << "l2 : " << l2 << endl;
    cout << "l3 : " << l3 << endl;

    l1.autoConcat(l2);
    cout << "l1.autoConcat(l2) : " << l1 << endl;

    l3 = l1.concat(l2);
    cout << "l3 = l1.concat(l2) : " << l3 << endl;

    Liste<int> l4;

    l4.supprimer(0);

    cout << "l4 :" << l4 << endl;

    l4 = l4.concat(l2);

    cout << "l4 = l4.concat(l2) : " << l4 << endl;

    l3.supprimer(3);
    cout << "l3 suppr pos=3 : " << l3 << endl;

#if ITERATOR

    cout << "Maniere STL Premier passage l1 " << endl;
    for(auto it = l1.begin(); it != l1.end(); ++it){
            cout << *it << endl;
    }
    cout << "Maniere STL Deuxieme passage l1 " << endl;
    for(Liste<int>::Iterateur it = l1.begin(); it != l1.end(); ++it){
            *it = 1;
    }
    cout << "Maniere STL Troisieme passage l1 " << endl;
    for(Liste<int>::Iterateur it = l1.begin(); it != l1.end(); it++){
            cout << *it << endl;
    }
    Liste<float> lll;
    cout << "STL Quatrieme passage lll vide " << endl;
    for(auto it = lll.begin(); it != lll.end(); it++){
            cout << *it << endl;
    }

    Liste<float> l;
    l.ajouter(3.0, 0);// ajouter
    l.ajouter(4.0, 0);
    l.ajouter(6.0, l.longueur());//longeur
    l.ajouter(7.0, 1);

    Liste<float>* pl = new Liste<float>;
    pl->ajouter(3.0, 0);// ajouter
    pl->ajouter(4.0, 0);
    pl->ajouter(6.0, pl->longueur());//longeur
    pl->ajouter(7.0, 1);

    cout << "l : " << l << endl;
    cout << "lp : " << *pl << endl;

    delete pl;// on nettoie

    cout << "FIN DE TEST" << endl;
    return 0;
}
#endif
