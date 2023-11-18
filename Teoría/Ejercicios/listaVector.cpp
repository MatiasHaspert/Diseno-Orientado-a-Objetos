#include <iostream>
#include <stdlib.h>

using namespace std;

class Vec4
{
    private:
    float v1, v2, v3, v4;

    public:
    Vec4()
    {
        v1 = 0.0;
        v2 = 0.0;
        v3 = 0.0;
        v4 = 0.0;
    }
    Vec4(float num1, float num2, float num3, float num4)
    {
        v1 = num1;
        v2 = num2;
        v3 = num3;
        v4 = num4;
    }
    void setv1(float v)
    {
        v1 = v;
    }
    void setv2(float v)
    {
        v2 = v;
    }
    void setv3(float v)
    {
        v3 = v;
    }
    void setv4(float v)
    {
        v4 = v;
    }
    float getv1()
    {
        return v1;
    }
    float getv2()
    {
        return v2;
    }
    float getv3()
    {
        return v3;
    }
    float getv4()
    {
        return v4;
    }
    void print()
    {
        cout<<"Vec[0]: "<<v1<<endl;
        cout<<"Vec[1]: "<<v2<<endl;
        cout<<"Vec[2]: "<<v3<<endl;
        cout<<"Vec[3]: "<<v4<<endl;
    }
};

class nodo
{
    public:
    Vec4 vect;
    nodo *sig;
    nodo()
    {
        sig=NULL;
    }
    void set_nodo(Vec4 v)
    {
        vect = v;
    }
    void set_sig(nodo *a)
    {
        sig = a;
    }
    bool si_esta(Vec4 a)
    {
        if(vect.getv1() == a.getv1() &&
            vect.getv2() == a.getv2() &&
            vect.getv3() == a.getv3() &&
            vect.getv4() == a.getv4())
        {
            return true;
        } 
        else
        {
            return false;
        }
    }
    void print()
    {
        vect.print();
    }
    
};

bool si_estaV (nodo *);

int main()
{
    Vec4 vector1(1.5, 0.5, 5, 3.2);
    Vec4 vector3(8, 9, 10, 11);
    Vec4 vector2;
    float a, b, c, d;

    cout<<"Ingrese valores al vector 2:";
    cout<<"\nIngresa el valor v1: ";
    cin>>a;
    cout<<"\nIngresa el valor v2: ";
    cin>>b;
    cout<<"\nIngresa el valor v3: ";
    cin>>c;
    cout<<"\nIngresa el valor v4: ";
    cin>>d;

    vector2.setv1(a);
    vector2.setv2(b);
    vector2.setv3(c);
    vector2.setv4(d);

    cout<<"\nVector 1:\n";
    vector1.print();
    cout<<"\nVector 2:\n";
    vector2.print();

    nodo *lista = new nodo;
    cout<<"\nEsta el vector 1 en la lista?: "<<lista->si_esta(vector1)<<endl;
    lista->set_nodo(vector1);
    cout<<"\nVector 1 en la lista:\n";
    lista->print();
    lista->set_sig(new nodo);
    lista->sig->set_nodo(vector2);
    cout<<"\nLista del nodo con el vector 2: "<<endl;
    lista->sig->print();
    cout<<"\nLista del nodo con el vector 1: "<<endl;
    lista->print();
    cout<<"\nNuevo vector3 agregado a la lista:\n";
    lista->sig->set_sig(new nodo);
    lista->sig->sig->set_nodo(vector3);
    cout<<"\nLista del nodo con el vector 3: "<<endl;
    lista->sig->sig->print();

    cout<<"\nEsta el vector 1 en la lista?: "<<lista->si_esta(vector1)<<endl;
    cout<<"\nEsta el vector 2 en la lista?: "<<lista->sig->si_esta(vector2)<<endl;
    cout<<"\nEsta el vector 3 en la lista?: "<<lista->sig->sig->si_esta(vector3)<<endl;
    
    return EXIT_SUCCESS;
}
