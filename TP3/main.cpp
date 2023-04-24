
#include <iostream>
#include "Fabrique.h"

int main(){
    std::cout << "Hello World" << std::endl;

    Fabrique fabrique;

    fabrique.production(10, 10);

    fabrique.control();

    return 0;
}