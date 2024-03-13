#include "header.h"

int main()
{
    Grafo grafo;

    cout<<"***KRUSKAL***"<<endl;

    grafo.insertar_vertice('a');
    grafo.insertar_vertice('b');
    grafo.insertar_vertice('c');
    grafo.insertar_vertice('d');
    grafo.insertar_vertice('e');
    grafo.insertar_vertice('f');
    
    grafo.insertar_arista('a', 'b', 6);
    grafo.insertar_arista('a', 'c', 1);
    grafo.insertar_arista('a', 'd', 5);
    grafo.insertar_arista('b', 'e', 3);
    grafo.insertar_arista('b', 'c', 5);
    grafo.insertar_arista('c', 'd', 5);
    grafo.insertar_arista('c', 'e', 6);
    grafo.insertar_arista('c', 'f', 4);
    grafo.insertar_arista('d', 'f', 2);
    grafo.insertar_arista('e', 'f', 6);

    grafo.kruskal();

    cout<<grafo<<endl;

    return EXIT_SUCCESS;
}

ostream & operator<<(ostream &os, Grafo grafi)
{
    cout<<"\nEl grafo es: "<<endl;
    for(auto x : grafi.E)
    {
        cout<<" "<<x.first.first<<" - "<<x.first.second<<", costo: "<<x.second<<endl;
    }

    cout<<"\nEl arbol mínimo es:"<<endl;
    for(auto arista: grafi.arbol_minimo)
    {
        cout<<"[("<<arista.first.first<<", "<<arista.first.second << "):"<<arista.second<<"]"<<endl;
    }

    return os;
}

void Grafo::insertar_vertice(const char &vertice)
{
    for(char x : V)
    {
        if(x == vertice)
        {
            cout<<"El vertice "<<vertice<<" ya existe, no se pudo insertar."<<endl;
            return;
        }     
    }
    //si el vertice no está lo inserto
    V.push_back(vertice);  
}

void Grafo::insertar_arista(const char &v1, const char &v2, const int &costo)
{
    bool v1INgrafo = false;
    bool v2INgrafo = false;
    for(auto x : V)
    {
        if(x == v1) 
            v1INgrafo = true;

        if(x == v2) 
            v2INgrafo = true;
    }

    if(v1INgrafo && v2INgrafo)
    {
        arista a = make_pair(make_pair(v1,v2), costo);
        E.push_back(a);
    }
}

void Grafo::inicial(const char &v, const char &indice)
{
    CE.nombres.insert(make_pair(indice,make_pair(v, NULL)));
    CE.encabezados.insert(make_pair(indice,make_pair(1,v)));
}

char Grafo::encuentra(const char &v)
{
    return CE.nombres[v].first;
}


void Grafo::combina(const char &A, const char &B)
{
    int sizeA = CE.encabezados[A].first;
    int sizeB = CE.encabezados[B].first;
    // encabezado de la componente dominante
    char ecDom = CE.encabezados[sizeA > sizeB ? A : B].second;
    // encabezado de la componente absorbida
    char ecAbs = CE.encabezados[sizeA <= sizeB ? A : B].second;

    char aux = CE.encabezados[ecAbs].second;
    while (CE.nombres[aux].second != (char)NULL)
    {
        // ahora el vertice del componente absorbido es parte del dominante
        CE.nombres[aux].first = ecDom;
        // y el siguiente tambien lo sera
        aux = CE.nombres[aux].second;
    }
    // ahora aux es el ultimo elemento del conjunto absorbido
    int menorSize = sizeA < sizeB ? sizeA : sizeB;

    CE.nombres[ecDom].second = aux;
    CE.nombres[aux].first = ecDom;
    CE.encabezados[ecAbs].first = 0;
    CE.encabezados[ecAbs].second = (char)NULL;
    CE.encabezados[ecDom].first += menorSize;
}

void Grafo::inserta(const arista &ar)
{
    grafo_ordenado.push(ar);
}

void Grafo::kruskal()
{
    for(arista ar : E)    //genero la cola de prioridad con los costos
    {
        inserta(ar);
    }
    for(char v : V) //genero las componentes individuales
    {
        inicial(v,v); 
    }

    int componentes = V.size();
    char comp1, comp2;
    arista aristaMenor;

    while(componentes > 1)
    {
        aristaMenor = grafo_ordenado.top(); //obtengo la arista de menor peso
        grafo_ordenado.pop(); // y la elimino de la cola de prioridad
        comp1 = encuentra(aristaMenor.first.first);
        comp2 = encuentra(aristaMenor.first.second);  // obtengo las componentes a las que pertencen los vertices de la arista
        if (comp1 != comp2) // si son diferente
        {                      
            combina(comp1, comp2);                // aplicamos la operacion combina
            componentes = componentes-1;         // restamos al contador
            arbol_minimo.push_back(aristaMenor);      // y sumamos al arbol minimo
        }
    }
}