/*
Ejercicio 2: Hacer una estructura llamada alumno, en la cual se tendrán los siguientes Campos: Nombre, edad, promedio, pedir datos al usuario para 3 alumnos, 
comprobar cuál de los 3 tiene el mejor promedio y posteriormente imprimir los datos del alumno.
*/

#include <iostream>
#include <stdlib.h>
#include <limits> // libreria para limpiar el buffer

using namespace std;

typedef struct
{
    char nombre[20];
    int edad;
    float prom;
}Alumno;

void datos (Alumno *);
void print_datos (Alumno );

int main()
{
    Alumno a1, a2, a3;
    
    cout<<"\nAlumno 1: ";
    datos(&a1);
    cout<<"\nAlumno 2: ";
    datos(&a2);
    cout<<"\nAlumno 3: ";
    datos(&a3);
    
    if((a1.prom > a2.prom) && (a1.prom > a3.prom))
    {
        print_datos(a1);
    }
    else if((a2.prom > a1.prom) && (a2.prom > a3.prom))
    {
        print_datos(a2);
    }
    else
    {
        print_datos(a3);
    }
    return EXIT_SUCCESS;
}

void datos (Alumno *a)
{
    cout<<"\nIngrese su nombre: ";
    cin.getline(a->nombre,20);
    cout<<"\nIngrese su edad: ";
    cin>>a->edad;
    // Limpia el buffer de entrada después de leer la edad
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\nIngrese su promedio: ";
    cin>>a->prom;
    // Limpia el buffer de entrada después de leer el promedio
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void print_datos(Alumno a)
{
    cout<<"\nEl mayor promedio es del alumno:\n";
    cout<<"Nombre del alumno: "<<a.nombre<<endl;
    cout<<"Edad:  "<<a.edad<<endl;
    cout<<"Promedio: "<<a.prom<<endl;
}