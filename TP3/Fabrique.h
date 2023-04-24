#ifndef __FABRIQUE_H
#define __FABRIQUE_H

#include "Voiture.h"
#include "Camion.h"
#include "ListeRecursif.h"

class Fabrique
{
    private:
        Liste<Vehicule*> listeVehicule;
    public:

        void production(int nbVoiture, int nbCamion){
            for (int i = 0; i < nbVoiture; i++){
                listeVehicule.ajouter(new Voiture(), i);
            }
            for (int i = 0; i < nbCamion; i++){
                listeVehicule.ajouter(new Camion(), i + nbVoiture);
            }
        }

        void control(){
            for (int i = 0; i < listeVehicule.longueur(); i++){
                listeVehicule[i]->control();
            }
        }

        void afficher(){
            for (int i = 0; i < listeVehicule.longueur(); i++){
                listeVehicule[i]->afficher();
            }
        }

        
};

#endif