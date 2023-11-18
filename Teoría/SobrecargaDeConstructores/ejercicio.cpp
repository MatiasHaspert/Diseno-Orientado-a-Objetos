#include <iostream>
#include <stdlib.h>

using namespace std;

class Tiempo
{
    private: //Atributos
        int horas,minutos,segundos;
    public: //Metodos
        Tiempo(int,int,int); //Constructor1
        Tiempo(int); //Constructor2
        void mostrarHora();
};

//Constructor1
Tiempo::Tiempo(int _horas, int _minutos, int _segundos)
{
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
}

//Constructor2
Tiempo::Tiempo(int s)
{
    horas = (s/3600);
    minutos = ((s-(horas*3600))/60); 
    segundos = (s-(horas*3600)-(minutos*60));
}

void Tiempo::mostrarHora(){
    
    cout<<"Tu tiempo es de: "<<horas<<" horas "<<minutos<<" minutos y "<<segundos<<" segundos"<<endl;
}
  
int main()
{
    Tiempo t1(24,59,1);
    Tiempo t2(40642);
 
    t1.mostrarHora();
    t2.mostrarHora();
 
    return 0;
}