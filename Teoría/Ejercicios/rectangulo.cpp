//rectangulo.cpp

#include "rectangulo.h"

rectangulo::rectangulo(float b, float a)
{
    
    base = b;
    altura = a;
}

rectangulo::rectangulo(){}

void rectangulo::setAltura(float a)
{
    altura = a;
}

float rectangulo::getAltura()
{
    return altura;
}

void rectangulo::setBase(float b)
{
    base = b;
}

float rectangulo::getBase()
{
    return base;
}

float rectangulo::area(){
    float a = 0.0;

    a = base * altura;

    return a;
}

float rectangulo::perimetro(){
    float p = 0.0;

    p = (base+altura) * 2;
    return p;
}

int main ()
{
    float base, altura;
    rectangulo R1;
    rectangulo R2(4.5, 2.0);

    cout<<"\nIngresa la base del rectangulo 1: "; cin>>base;
    cout<<"\nIngresa la altura del rectangulo 1: "; cin>>altura;

    R1.setBase(base);
    R1.setAltura(altura);

    cout << "R1: "<< "perimetro = " << R1.perimetro() << " - Area = " 
        << R1.area() << endl;

    cout << "R2: "<< "perimetro = " << R2.perimetro() << " - Area = " 
        << R2.area() << endl;

    return 0;
}