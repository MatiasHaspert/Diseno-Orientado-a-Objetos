/*
Escribe un programa que lea de la entrada estándar dos números y muestre en la salida estándar su suma, resta, multiplicación y división.
*/

#include <iostream>

using namespace std;

int main()
{
    int num1, num2;

    cout<<"Ingrese dos numeros y te dare el resultado de operaciones sobre ellos:\n";
    cout<<"Num1: ";
    cin>>num1;
    cout<<"Num2: ";
    cin>>num2;

    cout<<"\nSuma: "<<num1+num2;
    cout<<"\nResta: "<<num1-num2;
    cout<<"\nMultiplicacion: "<<num1*num2;
    cout<<"\nDivision: "<<num1/num2;

    return 0;
}