// Los iteradores son punteros. Están asociados a los contenedores y nos ayudarán en el momento de
// sus recorridos principalmente.
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>


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

    //iteradores, son punteros
    vector<int>::iterator I;

    I = vector1.begin(); // al iterador le asigno el comienzo del vector

    cout<<"\nvector[0] =  "<<*I<<endl;

    vector<int>::iterator i1, i2;

    i1 = vector1.begin();
    i2 = vector1.end();

    cout<<"\nVector ordenado mediante iteradores:\n";
    sort(i1, i2);
    for(; i1 != i2; i1++)
    {
        cout<<"Vector = "<<*i1<<endl;
    }
    
    return EXIT_SUCCESS;
}