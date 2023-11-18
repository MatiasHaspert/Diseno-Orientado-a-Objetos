#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class banco
{
    enum TipoSolicitud { SALDO_CERO = 1, SALDO_CREDITO, SALDO_DEBITO, TERMINAR };
    ifstream archivoClientesSalida;

    int solicitud;
    int cuenta;
    char nombre[30];
    double saldo;

    public:
    banco();
    ~banco(){ archivoClientesSalida.close(); }
    int obtenerSolicitud();
    bool debeMostrar( int, double );
    void imprimirLinea( int, const string, double );
    void lectura();
};

banco::banco()
{
    // el objeto ifstream abre el archivo
    archivoClientesSalida.open("Clientes.txt", ios::in );

    // sale del programa si ifstream no pudo abrir el archivo
    if ( !archivoClientesSalida )
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit( 1 );
    } // fin de if
} //fin del constructor

// obtiene la solicitud del usuario
int banco::obtenerSolicitud()
{
    cout << "\nEscriba la opcion" << endl
    << " 1 - Listar cuentas con saldos en cero" << endl
    << " 2 - Listar cuentas con saldos de credito" << endl
    << " 3 - Listar cuentas con saldos de debito" << endl
    << " 4 - Finalizar ejecucion" << fixed << showpoint;

    do
    {
        cout << "\n? ";
        cin >> solicitud;
    }while ( solicitud < SALDO_CERO && solicitud > TERMINAR );
    
    return solicitud;
} // fin de la ófuncin obtenerSolicitud

// determina si se va a mostrar el registro dado
bool banco::debeMostrar( int tipo, double saldo)
{
    //determina si se van a mostrar los saldos en cero
    if ( tipo == SALDO_CERO && saldo == 0 )
        return true;

    //determina si se van a mostrar los saldos de credito
    if ( tipo == SALDO_CREDITO && saldo < 0 )
        return true;
    //determina si se van a mostrar los saldos de debito
    if ( tipo == SALDO_DEBITO && saldo > 0 )
        return true;
    
    return false;
}

// muestra un solo registro del archivo
void banco::imprimirLinea( int cuenta, const string nombre, double saldo )
{
    cout << left << setw( 10 ) << cuenta << setw( 13 ) << nombre
    << setw( 7 ) << setprecision( 2 ) << right << saldo << endl;
}// fin de la ófuncin imprimirLinea

void banco::lectura()
{
    // obtiene la solicitud del usuario (por ejemplo, saldo en cero, de écrdito o édbito)
    solicitud = obtenerSolicitud();

    // procesa la solcitud del usuario
    while ( solicitud != TERMINAR )
    {
        switch ( solicitud )
        {
            case SALDO_CERO:
            cout << "\nCuentas con saldos en cero:\n";
            break;
            case SALDO_CREDITO:
            cout << "\nCuentas con saldos de credito:\n";
            break;
            case SALDO_DEBITO:
            cout << "\nCuentas con saldos de debito:\n";
            break;
        } // fin de switch

        // lee la cuenta, el nombre y el saldo del archivo
        archivoClientesSalida >> cuenta >> nombre >> saldo;
        //muestra el contenido del archivo (hasta eof)
        while (!archivoClientesSalida.eof())
        {
            // muestra el registro
            if(debeMostrar(solicitud, saldo))
                imprimirLinea(cuenta, nombre, saldo);

            // lee la cuenta, el nombre y el saldo del archivo
            archivoClientesSalida >> cuenta >> nombre >> saldo;
        } // fin de while interior

        archivoClientesSalida.clear(); // restablece eof para la siguiente entrada
        archivoClientesSalida.seekg( 0 ); // se reposiciona al inicio del archivo
        solicitud = obtenerSolicitud(); // obtiene una solicitud adicional del usuario
    } // fin de while exterior
}// fin de la funcion lectura

int main()
{
    banco *Banco = new banco();
    Banco->lectura();
    cout << "Fin de ejecucion." << endl;
    delete(Banco);
    return 0; // el destructor de ifstream cierra el archivo
} // fin de main