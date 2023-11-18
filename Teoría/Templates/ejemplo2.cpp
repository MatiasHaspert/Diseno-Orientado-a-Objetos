#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

template<class T> //instanciamos nuestro tipo de dato
const T& maximo (const T &a, const T &b)
{
    return (a >= b) ? a : b;
}
const char* maximo(const char* a, const char* b)
{
    if (strcmp(a, b) > 0)
        return a;
    else
        return b;
}

int main()
{
    cout << "con int ( 5 - 10):" << maximo (5, 10) << endl;
    cout << "con string: " << maximo("Hola", "zzChau") << endl;
    
    return EXIT_SUCCESS;
}