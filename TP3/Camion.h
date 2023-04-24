#ifndef __CAMION_H
#define __CAMION_H

#include "Vehicule.h"
#include <iostream>

class Camion : public Vehicule
{
    private:
        
    public:
        void afficher(){
            std::cout << "Je suis un camion avec l'id: " << getId() << std::endl;
        }
};

#endif