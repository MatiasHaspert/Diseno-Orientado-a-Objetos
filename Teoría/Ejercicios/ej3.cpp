#include <iostream>

using namespace std;

int main()
{
    float a, b, c, d;
    float resultado = 0;

    cout<<"Ingrese el numero A: "; cin>>a;
    cout<<"Ingrese el numero B: "; cin>>b;
    cout<<"Ingrese el numero C: "; cin>>c;
    cout<<"Ingrese el numero D: "; cin>>d;

    resultado = (a+b) / (c+d);

    cout.precision(2); //recorto el numero flotante
    cout<<"El resultado de la expresion es: "<<resultado<<endl;

    return 0;
}