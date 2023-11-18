#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //vector sin inicializar ni indicar tamaño
    vector<double> Vector_1;
    // Vector_1 = 10; // Error!!!
    // Vector[0]= 1; // Error!!!

    vector<int> Vector_3(10); //vector de tamaño 10

    //tamaño de 6 elementos, y todos los elementos se inicializan con el valor 3.1416
    vector<double> Vector_2(6,3.1416);
    // Vemos el tamaño del vector con .size()
    cout << Vector_2.size() << endl;

    // vemos el contenido del vector
    for (int i = 0; i < Vector_2.size(); i++)
    {
        //con el metodo .size() se obtiene el ñtamao del vector
        cout<<Vector_2[i]<<endl;
    }

    cout<<endl;

    return 0;
}