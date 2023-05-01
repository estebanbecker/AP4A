#ifndef __FABRIQUE_H
#define __FABRIQUE_H

#include "Voiture.h"
#include "Camion.h"
#include "ListeRecursif.h"

class Fabrique
{
    private:
        Liste<Vehicule*> listeVehicule;
        int nbVoit = 0;
        int nbCam = 0;
    public:

        void production(int nbVoiture, int nbCamion){
            nbVoit=nbVoiture;
            nbCam=nbCamion;
            for (int i = 0; i < nbVoiture; i++){
                listeVehicule.ajouter(new Voiture(), i);
            }
            for (int i = 0; i < nbCamion; i++){
                listeVehicule.ajouter(new Camion(), i + nbVoiture);
            }
        }

        void control(){
            for (Liste<Vehicule*>::Iterateur it = listeVehicule.begin(); it != listeVehicule.end(); it++){
                (*it)->control();
            }
        }

        void afficher(){
            for (Liste<Vehicule*>::Iterateur it = listeVehicule.begin(); it != listeVehicule.end(); it++){
                (*it)->afficher();
            }
        }

        ~Fabrique(){
            for (Liste<Vehicule*>::Iterateur it = listeVehicule.begin(); it != listeVehicule.end(); it++){
                delete *it;
            }
        }

        Fabrique(Fabrique& f){
            nbVoit=f.nbVoit;
            nbCam=f.nbCam;
            int i=0;
            for (Liste<Vehicule*>::Iterateur it = f.listeVehicule.begin(); it != f.listeVehicule.end(); it++){
                if (i<nbVoit){
                    listeVehicule.ajouter(new Voiture(), listeVehicule.longueur());
                }
                else{
                    listeVehicule.ajouter(new Camion(), listeVehicule.longueur());
                }
            }
        }

        Fabrique& operator=(Fabrique& f){
            if(this==&f){
                return *this;
            }

            nbVoit=f.nbVoit;
            nbCam=f.nbCam;

            for (Liste<Vehicule*>::Iterateur it = listeVehicule.begin(); it != listeVehicule.end(); it++){
                delete *it;
            }



            int i=0;
            for (Liste<Vehicule*>::Iterateur it = f.listeVehicule.begin(); it != f.listeVehicule.end(); it++){
                if (i<nbVoit){
                    listeVehicule.ajouter(new Voiture(), listeVehicule.longueur());
                }
                else{
                    listeVehicule.ajouter(new Camion(), listeVehicule.longueur());
                }
            }
            return *this;
        }

        Fabrique(){
            production(0,0);
        }
  
};

#endif