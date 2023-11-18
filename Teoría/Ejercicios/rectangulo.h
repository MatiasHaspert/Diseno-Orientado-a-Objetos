//rectangulo.h

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include<iostream>
using namespace std;

class rectangulo{
private:
    float altura, base;
public:
    rectangulo(float, float);
    rectangulo();

    void  setAltura(float);
    float getAltura();

    void  setBase(float);
    float getBase();

    float area();
    float perimetro();
};

#endif