#include <iostream>
#include <stdlib.h>

using namespace std;

// prototipo de la funcion
template <class TIPOD> // instancio TIPOD como cualquier tipo de dato
void valor_abs (TIPOD ); 

int main()
{
    int num = -10;
    float num2 = -14.567;
    double num3 = -543.543;

    valor_abs(num);
    valor_abs(num2);
    valor_abs(num3);
    
    return EXIT_SUCCESS;
}

template <class TIPOD>
void valor_abs (TIPOD numero)
{
    if(numero < 0)
    {
        numero = numero * -1;
    }

    cout<<"\nEl valor absoluto del numero es: "<<numero<<endl;

}
