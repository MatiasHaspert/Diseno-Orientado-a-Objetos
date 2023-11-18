#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{
    ofstream ar1("prueba2.txt", ios:: out);

    if(ar1.fail())
    {
        cerr<<"Ouch";
        exit(EXIT_FAILURE);
    }

    int num = 10;
    string nombre = "Matias";

    ar1<<num<<endl<<nombre<<endl;



    return EXIT_SUCCESS;
}