#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Alumno
{
public:
    Alumno();
    Alumno(int dni, string nombre, string mail)
    {
        this->dni = dni;
        this->nombre = nombre;
        this->mail = mail;
    }

    friend ostream& operator<<(ostream&, Alumno);
    void set_dni(int);
    const int get_dni();

    void set_nombre(string);
    string& get_nombre();

    void set_mail(string);
    string& get_mail();

    void mostrar_alumno(Alumno a);

private:
    int dni;
    string nombre;
    string mail;
};

ostream& operator<<(ostream& os, Alumno a)
{
    os<<"Alumno: "<<endl<<"Nombre: "<<a.get_nombre()<<endl<<"Dni: "<<a.get_dni()<<endl<<"Mail: "<<a.get_mail()<<endl;
    return os;
}
void Alumno::mostrar_alumno(Alumno a)
{
    cout<<"Alumno: "<<endl<<"Nombre: "<<a.get_nombre()<<endl<<"Dni: "<<a.get_dni()<<endl<<"Mail: "<<a.get_mail()<<endl;
}

void Alumno::set_dni(int dni)
{
    this->dni = dni;
}

const int Alumno::get_dni()
{
    return this->dni;
}

void Alumno::set_nombre(string nombre)
{
    this->nombre = nombre;
}

string& Alumno::get_nombre()
{
    return this->nombre;
}

void Alumno::set_mail(string mail)
{
    this->mail = mail;
}

string& Alumno::get_mail()
{
    return this->mail;
}

class Materia
{
public:
    Materia();
    Materia(int codigo, int cuatrimestre, Alumno a)
    {
        this->codigo = codigo;
        this->cuatrimestre = cuatrimestre;
        alumnos_incriptos.push_back(a);
    }

    void set_codigo(int);
    const int get_codigo();

    void set_cuatrimestre(int);
    const int get_cuatrimestre();

    void inscribir_alumno(Alumno);
    void lista_inscriptos();
    bool estaInscripto(int);

private:
    int codigo;
    int cuatrimestre;
    vector<Alumno> alumnos_incriptos;
};

void Materia::inscribir_alumno(Alumno a)
{
    alumnos_incriptos.push_back(a);
}

void Materia::lista_inscriptos()
{
    for(auto a : alumnos_incriptos)
    {
        cout<<a;
    }
}

bool Materia::estaInscripto(int dni)
{
    for(auto a : alumnos_incriptos)
    {
        if(a.get_dni() == dni)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    Alumno a1(44526051, "Matias Haspert", "mati202haspert@gmail.com");
    Alumno a2(43534534, "Lionel Messi", "liomessi2009@gmail.com");

    Materia matematica(43,1,a1);
    matematica.inscribir_alumno(a2);
    matematica.lista_inscriptos();

    cout<< "Esta inscripto el alumno 44526051 a la materia? "<<matematica.estaInscripto(44526051)<<endl;
    cout<< "Esta inscripto el alumno 44526051 a la materia? "<<matematica.estaInscripto(4452605)<<endl;

    return EXIT_SUCCESS;
}