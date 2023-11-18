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

int main()
{
    int numeroCuenta;
    char apellidoPaterno[15];
    char primerNombre[10];
    double saldo;

    fstream creditoSalida("credito.dat", ios::in | ios::out | ios::binary );

    // sale del programa si fstream no puede abrir el archivo
    if (!creditoSalida)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        exit( 1 );
    }// fin de if

    cout << "Escriba el numero de cuenta (de 1 a 100, 0 para terminar la entrada)\n? ";
    // requiere que el usuario especifique el únmero de cuenta
    datosCliente cliente;
    cin >> numeroCuenta;

    // el usuario introduce óinformacin, la cual se copia en el archivo
    while ( numeroCuenta > 0 && numeroCuenta <= 100 )
    {
        // el usuario introduce el apellido paterno, primer nombre y saldo
        cout << "Escriba apellido paterno, primer nombre y saldo\n? ";
        cin >> setw( 15 ) >> apellidoPaterno;
        cin >> setw( 10 ) >> primerNombre;
        cin >> saldo;

        //establece los valores de numeroCuenta, apellidoPaterno, primerNombre y saldo del registro
        cliente.establecerNroCuenta( numeroCuenta );
        cliente.establecerApellidoPaterno( apellidoPaterno );
        cliente.establecerNombre( primerNombre );
        cliente.establecerSaldo( saldo );

        // busca la óposicin en el archivo del registro especificado por el usuario
        creditoSalida.seekp((cliente.obtenerNroCuenta() - 1 ) * sizeof(datosCliente));

        // escribe la óinformacin especificada por el usuario en el archivo
        creditoSalida.write(reinterpret_cast< const char *>( &cliente ), sizeof(datosCliente));

        // permite al usuario escribir otro únmero de cuenta
        cout << "\nEscriba el numero de cuenta\n? ";
        cin >> numeroCuenta;   
    } // fin de while

    return 0;
} 