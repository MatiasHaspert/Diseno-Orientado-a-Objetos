#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class datosCliente
{
    private:

    int nroCuenta;
    char apellidoPaterno[15];
    char primerNombre[10];
    double saldo;

    public:
    // constructor predeterminado
    datosCliente(int = 0, string = "", string = "", double = 0.0);

    //funciones de acceso a numero de cuenta
    void establecerNroCuenta (int );
    int obtenerNroCuenta();

    //funciones de acceso a apellido
    void establecerApellidoPaterno(string );
    string obtenerApellidoPaterno();

    //funciones de acceso a nombre
    void establecerNombre(string );
    string obtenerNombre();

    //funciones de acceso a saldo
    void establecerSaldo (double );
    double obtenerSaldo();
};

datosCliente::datosCliente(int valorNroCuenta, string apellido, string nombre, double valorSaldo)
{
    establecerNroCuenta(valorNroCuenta);
    establecerApellidoPaterno(apellido);
    establecerNombre(nombre);
    establecerSaldo(valorSaldo);
}

int datosCliente::obtenerNroCuenta()
{
    return nroCuenta;
}

void datosCliente::establecerNroCuenta(int valorNroCuenta)
{
    nroCuenta = valorNroCuenta;
}

string datosCliente::obtenerApellidoPaterno()
{
    return apellidoPaterno;
}

void datosCliente::establecerApellidoPaterno(string cadenaApellido)
{
    // copia los 15 caracteres de la cadenaApellido
    char *valorApellido = cadenaApellido.data();
    int longitud = cadenaApellido.size();
    longitud = (longitud < 15 ? longitud : 14);
    strncpy (apellidoPaterno, valorApellido, longitud);
    apellidoPaterno[longitud] = '\0';
}

string datosCliente::obtenerNombre()
{
    return primerNombre;
}

void datosCliente::establecerNombre(string cadenaNombre)
{
    // copia los 10 caracteres de la cadenaNombre
    char *valorNombre = cadenaNombre.data();
    int longitud = cadenaNombre.size();
    longitud = (longitud < 10 ? longitud : 9);
    strncpy (primerNombre, valorNombre, longitud);
    primerNombre[longitud] = '\0';
}

double datosCliente::obtenerSaldo()
{
    return saldo;
}

void datosCliente::establecerSaldo(double valorS)
{
    saldo = valorS;
}

int main()
{
    ofstream creditoSalida("credito.dat", ios::out | ios::binary );

    // sale del programa si ofstream no pudo abrir el archivo
    if (!creditoSalida)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        exit( 1 );
    } // fin de if

    datosCliente clienteEnBlanco; // el constructor pone en ceros cada miembro de datos

    // escribe 100 registros en blanco en el archivo
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write( reinterpret_cast< const char * >( &clienteEnBlanco ), sizeof(datosCliente));

    return 0;
} // fin de main


