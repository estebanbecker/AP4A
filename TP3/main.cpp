
#include <iostream>
#include "Fabrique.h"

int main(){
    
    srand(time(nullptr));

    std::cout << "Hello World" << std::endl;

    Fabrique fabrique;

    fabrique.production(15, 15);

    fabrique.afficher();

    fabrique.control();

    return 0;
}