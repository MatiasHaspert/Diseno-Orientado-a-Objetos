#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int>vector1(10, 1);

    cout<<"\nTamaño del vector: "<<vector1.size()<<endl;

    vector1.push_back(3); // permite agregar un elemento al vector;

    cout<<"\nNuevo tamaño del vector: "<<vector1.size()<<endl;
    
    for (size_t i = 0; i < vector1.size(); i++)
    {
        cout<<"\nVector 1 = "<<vector1[i];
    }
    
    //pop_back elimina el ultimo elemento (no lo retorna)
    vector1.pop_back();

    for (size_t i = 0; i < vector1.size(); i++)
    {
        cout<<"\nVector 1 = "<<vector1[i];
    }

    cout<<"\n\nTamaño del vector: "<<vector1.size()<<endl;
    vector1.resize(5);
    //ahora su tamaño es
    cout<<"\nNuevo tamaño del vector: "<<vector1.size()<<endl;
    //esto provoca una perdida de informacion
    for (size_t i = 0; i < vector1.size(); i++)
    {
        cout<<"\nVector 1 = "<<vector1[i];
    }

    // borrado de elementos
    vector<int> vector2(10);
    for (size_t i = 0; i < vector2.size(); i++)
    {
        vector2[i] = i+1;
    }
    
    cout<<"\n\nTamaño del vector 2: "<<vector2.size()<<endl;
    cout << "\n--------------" << endl;
    for (size_t i = 0; i < vector2.size(); i++)
    {
        cout<<"\nVector 2 = "<<vector2[i];
    }

    // IMPORTANTE erase() no recibe elementos sino posiciones!!!!
    vector2.erase(vector2.begin()+3, vector2.begin()+6);
    cout << "\n--------------" << endl;
    for(size_t i=0; i < vector2.size() ;i++)
    {
        cout << "Vector 2 = " << vector2[i] << endl;
    }
    cout << "El tamaño despues del borrado de vector 2 es " << vector2.size() << endl;

    // insert permite agregar un valor en cualquier posicion del vector
    vector2.insert(vector2.begin()+3,4);
    cout<<endl;
    for(size_t i=0; i < vector2.size() ;i++)
    {
        cout << "Vector 2 = " << vector2[i] << endl;
    }

    // otra forma (de varias)
    vector2.insert(vector2.begin()+4,4,-1); //a partir de la posicion [4] inserta cuatro -1
    cout<<endl;
    for(size_t i=0; i < vector2.size() ;i++)
    {
        cout << "Vector 2 = " << vector2[i] << endl;
    }

    cout<<endl;
    return 0;
}