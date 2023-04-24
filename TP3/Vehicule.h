#ifndef __VEHICULE_H
#define __VEHICULE_H

#include <cstdlib>
#include <iostream>

class Vehicule
{
private:
    int id;
    static int nbVehicule;
    
public:

    Vehicule(){
        id = nbVehicule++;
    }

    void virtual afficher() = 0;
    int getId() const { return id; }
    void virtual control() = 0;

};

class Esystem
{
    private:
        bool enable;
        int value;

        virtual bool check() = 0;

    protected:

        void setValue(int v){
            value = v;
        }

        int getValue(){
            return value;
        }

        Esystem(int v){
            enable = check();
            value = v;
        }

        virtual int warning(){
            if (enable){
                return 0;
            }
            else{
                return value;
            }
        }
}

class Estart : public Esystem
{
    private:
        bool check(){
            // Has the probability to return true of 2%
            return (rand() % 100) < 2;
        }

    public:
        Estart() : Esystem(2) {}

        int warning(){
            int i = Esystem::warning();

            if( i == 0){
                return 0;
            }
            else{
                cout << "Panne de demarrage" << endl;
                return i ;
            }
}

class Emoteur : public Esystem
{
    private:
        bool check(){
            // Has the probability to return true of 3%
            return (rand() % 100) < 3;
        }

    public:
        Emoteur() : Esystem(3) {}

        int warning(){
            int i = Esystem::warning();

            if( i == 0){
                return 0;
            }
            else{
                cout << "Panne de moteur" << endl;
                return i ;
            }
}

class Efrein : public Esystem
{
    private:
        bool check(){
            // Has the probability to return true of 5%
            return (rand() % 100) < 5;
        }

    public:
        Efrein() : Esystem(5) {}

        int warning(){
            int i = Esystem::warning();

            if( i == 0){
                return 0;
            }
            else{
                cout << "Panne de freinage" << endl;
                return i ;
            }
        }
}

class Efeux : public Esystem
{
    private:
        bool check(){
            // Has the probability to return true of 8%
            return (rand() % 100) < 8;
        }

    public:
        Efeux() : Esystem(8) {}

        int warning(){
            int i = Esystem::warning();

            if( i == 0){
                return 0;
            }
            else{
                cout << "Panne de feux" << endl;
                return i ;
            }
}

#endif