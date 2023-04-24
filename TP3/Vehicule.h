#ifndef __VEHICULE_H
#define __VEHICULE_H

#include <cstdlib>
#include <iostream>
#include <string>


class Esystem
{
    private:
        
        int value;

    protected:

        bool enable;

        virtual bool check() = 0;

        void setValue(int v){
            value = v;
        }

        int getValue(){
            return value;
        }

        Esystem(int v){
            value = v;
        }

    public:

        virtual int warning(){
            if (enable){
                return 0;
            }
            else{
                return value;
            }
        }
};

class Estart : public Esystem
{
    protected:
        bool check(){
            // Has the probability to false true of 2%
            return (rand() % 100) > 2;
        }

    public:
        Estart() : Esystem(2) {
            enable = check();
        }

        int warning(){
            int i = Esystem::warning();

            if( i == 0){
                return 0;
            }
            else{
                std::cout << "Panne de demarrage" << std::endl;
                return i ;
            }
        }
};

class Emoteur : public Esystem
{
    protected:
        bool check(){
            // Has the probability to return false of 3%
            return (rand() % 100) > 3;
        }

    public:
        Emoteur() : Esystem(3) {
            enable = check();
        }

        int warning(){
            int i = Esystem::warning();

            if( i == 0){
                return 0;
            }
            else{
                std::cout << "Panne de moteur" << std::endl;
                return i ;
            }
        }
};

class Efrein : public Esystem
{
    protected:
        bool check(){
            // Has the probability to return false of 5%
            return (rand() % 100) > 5;
        }

    public:
        Efrein() : Esystem(5) {
            enable = check();
        }

        int warning(){
            int i = Esystem::warning();

            if( i == 0){
                return 0;
            }
            else{
                std::cout << "Panne de freinage" << std::endl;
                return i ;
            }
        }
};

class Efeux : public Esystem
{
    protected:
        bool check(){
            // Has the probability to return flase of 8%
            return (rand() % 100) > 8;
        }

    public:
        Efeux() : Esystem(8) {
            enable = check();
        }

        int warning(){
            int i = Esystem::warning();

            if( i == 0){
                return 0;
            }
            else{
                std::cout << "Panne de feux" << std::endl;
                return i ;
            }
        }
};

class Vehicule
{
private:
    int id;
    static int nbVehicule;

protected:

    Esystem *system[4];
    
public:

    void virtual afficher() = 0;
    int getId() const { return id; }
    void virtual control() = 0;

    Vehicule(){
        
        system[0] = new Estart();
        system[1] = new Emoteur();
        system[2] = new Efrein();
        system[3] = new Efeux();

        

        id = nbVehicule++;
    }

    ~Vehicule(){
        for (int i = 0; i < 4; i++){
            delete system[i];
        }
    }

    Vehicule(const Vehicule& v){
        system[0] = new Estart(*(Estart*)v.system[0]);
        system[1] = new Emoteur(*(Emoteur*)v.system[1]);
        system[2] = new Efrein(*(Efrein*)v.system[2]);
        system[3] = new Efeux(*(Efeux*)v.system[3]);
    }

    Vehicule& operator=(const Vehicule& v){
        if (this != &v){
            delete system[0];
            delete system[1];
            delete system[2];
            delete system[3];
            system[0] = new Estart(*(Estart*)v.system[0]);
            system[1] = new Emoteur(*(Emoteur*)v.system[1]);
            system[2] = new Efrein(*(Efrein*)v.system[2]);
            system[3] = new Efeux(*(Efeux*)v.system[3]);
        }
        return *this;
    }

};


#endif