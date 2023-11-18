#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<int>vector1(10);

    for (size_t i = 0, j = 10; i < 10; i++, j--)
    {
        vector1[i] = j+1;
    }

    cout<<"\nTamaña del vector: "<<vector1.size()<<endl;
    for (size_t i = 0; i < vector1.size(); i++)
    {
        cout<<"Vector =  "<<vector1[i]<<endl;
    }

    // Con los contenedores podemos usar una ófuncin
    // de la lib algorithm muy útil. Antes hay que
    // incluir la lib #include<algortihm>

    sort(vector1.begin(), vector1.end());

    cout << endl;
    for(size_t i=0; i < vector1.size() ;i++)
    {
        cout << "Vector = " << vector1[i] << endl;
    }

    vector<string> Nombres;
    Nombres.push_back("Pablo");
    Nombres.push_back("Juan");
    Nombres.push_back("Alicia");
    for(size_t i=0; i < Nombres.size() ;i++)
    {
        cout << Nombres[i] << " ";
    }
    cout << endl;

    sort(Nombres.begin(), Nombres.end());

    for(size_t i=0; i < Nombres.size() ;i++)
    {
        cout << Nombres[i] << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}