#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int *i {nullptr}; //incializo el i a 0

    i = new int; // reservo memoria dinamica para un entero
    delete i;

    int *p = new int[30]; // p apunta a un arreglo dinamico de 30 enteros
    delete [] p; //se requiere liberar todas las posiciones

    return EXIT_SUCCESS; 

}