#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T> //instanciamos nuestro tipo de dato
const T& maximo (const T &a, const T &b)
{
    return (a >= b) ? a : b;
}
int main()
{
    string a = "Hola";
    string b = "zzChauchau";
    cout << "con int ( 5 - 10):" << maximo (5, 10) << endl;
    cout << "con string: " << maximo(a, b) << endl;

    return EXIT_SUCCESS;
}