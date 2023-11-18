#include <iostream>
#include <stdlib.h>

using namespace std;

template <class dato>
void despliegue (dato );

int main()
{
    int num = 14;
    char nombre[10] = "Matias";
    char letra = 'H';
    float altura = 1.76;

    despliegue(nombre);
    despliegue(letra);
    despliegue(altura);
    despliegue(num);



    return EXIT_SUCCESS;
}

template <class dato>
void despliegue (dato valor)
{
    cout<<"El valor es "<<valor<<endl;
}
