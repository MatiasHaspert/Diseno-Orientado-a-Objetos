#include "vec.cpp"

class Nodo
{
    public:

    Nodo();
    Nodo(Vec *);
    ~Nodo();

    Vec *vector;
    Nodo *sig;

    void borrar_todo();
    bool si_estaV(Vec);
    void printN();
};

Nodo::Nodo()
{
    vector = NULL;
    sig = NULL;
}

//Instancia un nuevo nodo
Nodo::Nodo(Vec *v)
{
    vector = v;
    sig = NULL;
}

//Elimina todos los nodos
void Nodo::borrar_todo()
{
    if(sig) // sig != NULL
    {
        sig->borrar_todo();
    }
    delete this; //elimina el objeto actual
}

//Imprimir un nodo
void Nodo::printN()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << vector << "-> ";
}

bool Nodo::si_estaV(Vec a)
{
    if(vector->getv1() == a.getv1() &&
        vector->getv2() == a.getv2() &&
        vector->getv3() == a.getv3() &&
        vector->getv4() == a.getv4())
    {
        return true;
    } 
    else
    {
        return false;
    }
}

Nodo::~Nodo(){}

//////////////
class Lista
{
    private:
	Nodo *inicio;
    public:
	Lista();
	~Lista();

	void insert(Vec *);
	void print();
	void borrar_vec(Nodo *);	
	void busca(Vec);
};

Lista::Lista()
{
    inicio = NULL;
}

void Lista::insert(Vec *v)
{
    Nodo *nuevo_nodo = new Nodo(v);
    Nodo *temp = inicio;

    if(temp == NULL)
    {
        inicio = nuevo_nodo;
    }
    else
    {
        while(temp->sig != NULL) // nos paramos en el ultimo nodo
        {
            temp = temp->sig;
        }

        temp->sig = nuevo_nodo; // e insertamos el nuevo nodo
    }
}

void Lista::print()
{
    Nodo *temp = inicio;

    if(temp == NULL)
    {
        cout<<"\nLista vacia.\n";
    }
    else
    {
        while(temp != NULL)
        {
            temp->printN();
            if(temp->sig == NULL)
            {
                cout<<"NULL"<<endl;
            }
            temp = temp->sig;
        }
    }

    cout<<endl<<endl;
}

void Lista::busca(Vec v)
{
    Nodo *temp = inicio;
    int cont = 1;
    int cont2 = 0;

    if(temp != NULL)
    {
        if(temp->si_estaV(v))
        {
            cout<<"\nEl dato se encuentra en la posición: " <<cont<<endl;
            cont2++;
        }
        cont++;

        temp = temp->sig;
    }

    if(cont2 == 0)
    {
        cout<<"\nEl dato no se encontro en la lista.\n"<<endl;
    }
}

Lista::~Lista(){inicio->borrar_todo();}

int main()
{
    Vec *v1 = new Vec;
    Vec *v2 = new Vec;
    Vec *v3 = new Vec;

    cout<<"\nIngrese los valores al vector 1:\n";
    v1->ingresa_datos(v1);
    cout<<"\nIngrese los valores al vector 2:\n";
    v2->ingresa_datos(v2);
    cout<<"\nIngrese los valores al vector 3:\n";
    v3->ingresa_datos(v3);
    Lista l;

    l.insert(v1);
    l.insert(v2);
    l.insert(v3);

    l.print();


    return 0;
}