#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Ciudad
{
public:
    Ciudad();
    Ciudad(string nombre, int codigo_postal)
    {
        this->nombre = nombre;
        this->codigo_postal = codigo_postal;
    }

    friend ostream& operator<< (ostream &os, Ciudad);
    //setters

    //getters
    string get_nombre()
    {
        return nombre;
    }

    int get_codigo()
    {
        return codigo_postal;
    }
    void mostrar_ciudad(Ciudad);
private:
    string nombre;
    int codigo_postal;
};

void Ciudad::mostrar_ciudad(Ciudad c)
{
    cout<<"Ciudad: "<<c.get_nombre()<<endl<<"Codigo postal: "<<c.get_codigo()<<endl;
}

ostream& operator <<(ostream &os, Ciudad c)
{
    os<<"Ciudad: "<<c.get_nombre()<<endl<<"Codigo postal: "<<c.get_codigo()<<endl;
    return os;
}
class Provincia
{
public:
    Provincia() : nombre(0), superficie(0), ciudades(0){};
    Provincia(string nombre, int superficie, Ciudad c)
    {
        this->nombre = nombre;
        this->superficie = superficie;
        ciudades.push_back(c);
    }

    //setters

    void insertar_ciudad(Ciudad);
    //getters
    string get_nombre()
    {
        return nombre;
    }
    void ciudadesDeLaProvincha(Provincia p);
private:
    string nombre;
    int superficie;
    vector <Ciudad> ciudades;
};

void Provincia::insertar_ciudad(Ciudad c)
{
    ciudades.push_back(c);
}
void Provincia::ciudadesDeLaProvincha(Provincia p)
{
    cout<<"Ciudades de la provincia "<<p.get_nombre()<<endl;

    for(auto a : ciudades)
    {
        a.mostrar_ciudad(a);
    }
}

int main()
{
    Ciudad c1("San Jorge",2452);
    Ciudad c2("Rosario", 2000);

    vector<Ciudad> ciudades{c1,c2};

    cout<<"Lista de ciudades:"<<endl;
    for(auto c : ciudades)
    {
        c.mostrar_ciudad(c);
    }


    Provincia p1("Santa Fe", 432, c1);
    
    p1.insertar_ciudad(c2);
    
    p1.ciudadesDeLaProvincha(p1);

    Ciudad c3("Buenos Aires", 2500);
    ciudades.push_back(c3);

    cout<<endl<<"Lista de ciudades:"<<endl;
    for(auto c : ciudades)
    {
        cout<< c;
    }
    

    return EXIT_SUCCESS;
}