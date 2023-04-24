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

        void control(){
            int sum = 0;
            int count = 0;
            for (int i = 0; i < 4; i++){
                int state = system[i]->warning();
                if (state != 0){
                    sum += state;
                    count++;
                }
            }

            if (sum >= 8 || count >= 2){
                std::cout << "Le systeme de demarrage de la voiture " << getId() << " est en bloqué" << std::endl;
            }
        }
};

#endif