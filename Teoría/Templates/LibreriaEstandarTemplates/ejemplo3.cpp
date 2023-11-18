//tuplas
#include<iostream>
#include<tuple>

using namespace std;

tuple<int, int, int, int> operaciones( int x, int y)
{
    return make_tuple(x+y, x-y, x*y, x/y);
}

int main ()
{
    tuple<int, int, int, int> resultado = operaciones (6, 2);

    cout<< "Resultado\n";
    cout<< "Suma: " << get<0>(resultado) << endl;
    cout<< "resta: " << get<1>(resultado) << endl;
    cout<< "Multiplicación: " << get<2>(resultado) << endl;
    cout<< "Division: " << get<3>(resultado) << endl;
    
    return 0;
}

/*
int main ()
{
    int sum, resta, mult, div;
    
    tie(sum, resta, mult, div) = operaciones (6, 2);
    cout<< "Resultado\n";
    cout<< "Suma: " << sum << endl;
    cout<< "resta: " << resta << endl;
    cout<< "Multiplicación: " << mult << endl;
    cout<< "Division: " << div << endl;
    return 0;

    tie debe usarse para cuando necesitamos tuplas
    de referencias. Ejemplo:
    tuple<int&, int&> min_max(int& x, int& y)
    {
        if(x < y)
            return tie(x, y);
        else
            return tie(y, x);
    }
}
*/