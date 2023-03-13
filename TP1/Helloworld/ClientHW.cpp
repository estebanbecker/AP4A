#include "HelloW.hpp"
#include "HelloA.hpp"
#include "HelloB.hpp"

int main(int argc, char **argv){
    HelloW hello;
    hello.affiche();

    HelloA helloA;
    helloA.affiche();
    
    HelloB helloB;
    helloB.affiche();

    return 0;
}