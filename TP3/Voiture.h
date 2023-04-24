#ifndef __VOITURE_H
#define __VOITURE_H

#include "Vehicule.h"
#include <iostream>

class Voiture : public Vehicule
{
    private:
        
    public:
        void afficher(){
            std::cout << "Je suis une Voiture avec l'id: " << getId() << std::endl;
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

            if (sum >= 10 || count >= 3){
                std::cout << "Le systeme de demarrage de la voiture " << getId() << " est en bloqué" << std::endl;
            }
        }

};

#endif