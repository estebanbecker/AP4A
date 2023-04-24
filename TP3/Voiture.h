#ifndef __VOITURE_H
#define __VOITURE_H

#include "Vehicule.h"
#include <iostream>

class Voiture : public Vehicule
{
    private:
        Esystem *system[4];
        
    public:
        void afficher(){
            std::cout << "Je suis une Voiture avec l'id: " << getId() << std::endl;
        }

        void control(){
            
        }

        Voiture(){
            
            system[0] = new Estart();
            system[1] = new Emoteur();
            system[2] = new Eroue();
        }
};

#endif