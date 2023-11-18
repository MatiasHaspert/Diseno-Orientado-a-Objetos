#include <iostream>
#include <stdlib.h>

using namespace std;

class Fecha
{
    private:
        int dia, mes, anio;
    public:
        Fecha(int, int, int); //constructor 1
        Fecha(long); // constructor 2
        void mostraFecha();
};

// 17 9 2023   --- 20230917

// constructor 2
Fecha::Fecha(long _fecha)
{
    anio = int(_fecha/10000); //extraer el anio
    mes  = int(((_fecha-anio*10000)/100)); // extrar el mes
    dia  = int(_fecha-anio*10000-mes*100); // extrar el dia
}

// constructor 1
Fecha::Fecha(int _dia, int _mes, int _anio)
{
    dia = _dia;
    mes = _mes;
    anio = _anio; 
}

void Fecha::mostraFecha()
{
    cout<<"La fecha es:  "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main()
{
    Fecha hoy(17,9,2023);
    Fecha ayer(20230916);

    hoy.mostraFecha();
    ayer.mostraFecha();

    return EXIT_SUCCESS;
}