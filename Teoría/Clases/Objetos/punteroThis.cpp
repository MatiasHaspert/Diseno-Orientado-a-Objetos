#include <iostream>
#include <stdlib.h>

using namespace std;

//Para diferenciar a la variable input de la miembro se utiliza this.
// Para retornarse a sí mismo, el objeto también utiliza this.


class Costo
{
    private:
        int valor;
    public:
        void setValor(int);
        Costo& incrementa();
};

void Costo::setValor(int v)
{
    this->valor = v;
}

Costo& Costo::incrementa()
{
    valor++;
    cout<<valor<<endl;
    return *this;
}
int main()
{
    Costo v1;

    v1.setValor(10);
    v1.incrementa();

    return EXIT_SUCCESS;
}