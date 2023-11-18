#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void fun1 (char *, vector<char> );
void fun2 ();
void g(string );
void fun3();

int main()
{
    fun2();

    return EXIT_SUCCESS;
}

void fun(char *p, vector<char> v)
{
    string s0; // la string esta vacia
    string s00 = ""; // la string esta vacia

    //string s1 = 'a';  error!!!! no se puede convertir un caracter en string
    //string s2 = 7;    error!!!! no hay conversion de int a string
    //string s3(7);     error!!! no hay constructor que tome un int

    string s4(7, 'a'); // crea un string con 7 copias de a, o sea, "aaaaaaa"
    string s5("Frodo"); // copia de "Frodo"
    string s6 = s5; // copia de s5

    string s7(s5, 3, 4);//s5[3] y s5[4] o sea copia "do"
    string s8(p+7, 3); //p[7], p[8] y p[9]
    string s9(p, 7, 3); //string(string(p), 7, 3) no es recomendable
    string s10(v.begin(), v.end()); //copiar todos los caracteres de v
}

void fun2()
{
    string s = "Snobol4";
    string s2(s, 100, 2); //posicion del caracter mas alla del final
    //de la cadena: lanza error out_of_range()
    string s3(s, 2, 100); //Recuento de caracteres demasiado grande:
    //equivalente a s3(s, 2, s.size()-2)
    string s4(s, 2, string::npos); //los caracteres a partir de s[2]
}

void g(string s)
{
    string s5(s, -2, 3); //posicion grande!! lanza out_of_range();
    
    string s6(s, 3, -2); //recuento de caracteres grande! bien!
}

// asignaciones
void fun3()
{
    string s1 = "Knould";
    string s2 = "Tod";
    
    s1 = s2; //dos copias de "Tod"
    s2[1] = 'u'; //s2 es "Tud"
}

