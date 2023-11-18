#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main ()
{
    /*Aquí se crea un objeto map llamado ejemplo que almacena pares clave-valor, 
    donde la clave es de tipo int y el valor es de tipo string*/
    map<int, string>ejemplo;
    
    ejemplo[0]="Pablo";
    ejemplo[1]="otro Pablo";
    
    /*Se utiliza la función find() para buscar un elemento en el mapa ejemplo con clave 1. 
    La función find() devuelve un iterador que apunta al elemento si se encuentra, o al final del mapa si no se encuentra. 
    El resultado se almacena en la variable x, y el tipo de x se infiere automáticamente como un iterador a un par clave-valor en el mapa ejemplo.*/
    cout<< "Elemento\n";
    auto x = ejemplo.find(1); //fin busca un elemento

    cout<< "Clave " << x->first << " Dato: " << x->second<<endl;

    auto e = ejemplo.find(0);
    cout<<endl;
    for(unsigned i = 0 ; i < ejemplo.size(); i++)
    {
        cout<< "Clave " << e->first << " Dato: " << e->second<<endl;
        e++;
    }
    
    return 0;
}