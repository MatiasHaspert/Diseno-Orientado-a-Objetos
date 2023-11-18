#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

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

void imprimirLinea(ostream&, datosCliente& ); // prototipo

int main()
{
    ifstream creditoEntrada( "credito.dat", ios::in | ios::binary );

    // sale del programa si ifstream no puede abrir el archivo
    if ( !creditoEntrada )
    {
        cerr << "No se pudo abrir el archivo." << endl;
        exit( 1 );
    }// fin de if

    cout << left << setw( 10 ) << "Cuenta" << setw( 16 )
    << "Apellido" << setw( 11 ) << "Nombre" << left
    << setw( 10 ) << right << "Saldo" << endl;

    datosCliente cliente; // crea un registro

    // lee el primer registro del archivo
    creditoEntrada.read( reinterpret_cast< char * >( &cliente ),sizeof( datosCliente ) );

    // lee todos los registros del archivo
    while (creditoEntrada && !creditoEntrada.eof())
    {
        // muestra un registro
        if (cliente.obtenerNroCuenta() != 0 )
            imprimirLinea(cout, cliente );

        // lee el siguiente registro del archivo
        creditoEntrada.read( reinterpret_cast< char * >(&cliente), sizeof(datosCliente));
    } // fin de while

    return 0;
} // fin de main

// muestra un solo registro
void imprimirLinea( ostream &salida, datosCliente &registro )
{
    salida << left << setw( 10 ) << registro.obtenerNroCuenta()
    << setw( 16 ) << registro.obtenerApellidoPaterno()
    << setw( 11 ) << registro.obtenerNombre()<< left
    << setw( 10 ) << setprecision( 2 ) << right << fixed
    << registro.obtenerSaldo() << endl;
} // fin de la ófuncin imprimirLinea