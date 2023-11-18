// Pair, muy similar a una tupla pero limitado a dos elementos
#include<iostream>
#include<utility>

using namespace std;

pair<int, int> sum_resta( int x, int y)
{
    return {x+y, x-y};
}

int main ()
{
    pair<int, int> resultado = sum_resta (6, 2);
    cout<< "Resultado\n";
    cout<< "Suma: " << resultado.first << endl;
    cout<< "resta: " << resultado.second << endl;
    
    return 0;
}

