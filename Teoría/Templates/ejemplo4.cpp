#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<typename T>

class Mercaderia
{
    string nombre;
    T medida;
    public:
    Mercaderia(string n, T m): nombre{n}, medida{m} {}
    string get_nombre(){return nombre;}
    T get_medida() {return medida;}
    template<class U>
    friend ostream& operator<< (ostream& os, Mercaderia<U>& M);
};

template<class U>
ostream& operator<< (ostream& os, Mercaderia<U>& M)
{
    os<< "Mercaderia: " << M.nombre << "-->cantidad: " << M.medida << endl;
    return os;
}

int main ()
{
    Mercaderia<int> tornillos("tornillos", 150);
    Mercaderia<float> kerosene("kerosene", 256.5);
    cout << tornillos << kerosene;
    return 0;
}

