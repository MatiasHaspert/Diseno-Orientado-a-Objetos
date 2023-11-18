#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <stdlib.h>
#include <stdexcept> //para excepciones
#define NAME_ARCHIVO "cache.dat"

using namespace std;

template<class T>
class CacheManager
{
    private:
    int capacity;
    int MRU;
    map <string, pair<T, int>> cache_data; // <Clave, <Objeto, indice de uso>>
    void write_file(string, T);
    T getFile(string);
    bool inFile(string);
    string getKey(T);
    public:
    CacheManager(int cap) : capacity(cap), MRU(0){};
    ~CacheManager(){};

    void insert(string key, T obj);
    T get(string key);
    void show_cache();
};

template<class T>
bool CacheManager<T>::inFile(string clave)
{
    ifstream archivo(NAME_ARCHIVO, ios::in | ios::binary);
    
    if(archivo.fail())
    {
        cerr<<"Error al abrir el archivo."<<endl;
        exit(EXIT_FAILURE);
    }

    string aux;
    while(archivo>>aux)
    {
        if(aux == clave)
        {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

template<class T>
void CacheManager<T>::write_file(string clave, T obj)
{
    fstream archivo(NAME_ARCHIVO, ios::out | ios::in | ios::binary);
    if(archivo.fail())
    {
        cerr<<"Error al abrir el archivo."<<endl;
        exit(EXIT_FAILURE);
    }

    if(inFile(clave))
    {
        //busco la clave en el archivo y actualizo el objeto
        //calcula la posición actual en el archivo
        long pos = archivo.tellg();
        string aux;
        while (!archivo.eof())
        {
            archivo>>aux;
            if (aux == clave)
            {
                archivo.seekp(pos);
                archivo.write(reinterpret_cast<const char*>(&obj), sizeof(T));
                //cierra el archivo y termina la función
                archivo.close();
                return;
            }
            pos = archivo.tellg();
        }
    }
    else
    {
        archivo.seekp(0, ios::end);//me posiciono en el final
        archivo<<clave<<" "<<obj<<endl;
    }
}

template<class T>
void CacheManager<T>::insert(string clave, T obj)
{
    cache_data[clave] = make_pair(obj, ++MRU);

    if(cache_data.size() > capacity)
    {
        auto it = cache_data.begin();
        auto aux = it;

        while(it != cache_data.end())
        {
            // se busca el de menor MRU
            if(it->second.second < aux->second.second)
            {
                aux = it;
            }
            it++;
        }
        cache_data.erase(aux);
    }
    write_file(clave,obj);
}

template<class T>
string CacheManager<T>::getKey(T obj)
{
    ifstream archivo(NAME_ARCHIVO, ios::in | ios::binary);
    string clave;

    if(archivo.fail())
    {
        cerr << "Error al abrir el archivo." << endl;
        exit(EXIT_FAILURE);
    }

    while(archivo >> clave)
    {
        T objetoEnArchivo;
        archivo.read(reinterpret_cast<char*>(&objetoEnArchivo), sizeof(objetoEnArchivo));

        if (objetoEnArchivo == obj)
        {
            archivo.close();
            return clave;
        }
    }

    archivo.close();
    return ""; // Devuelve una cadena vacía si el objeto no se encuentra en el archivo
}

template<class T>
T CacheManager<T>::getFile(string clave)
{
    ifstream archivo(NAME_ARCHIVO, ios::in | ios::binary);
    T obj;

    if(archivo.fail())
    {
        cerr<<"Error al abrir el archivo."<<endl;
        exit(EXIT_FAILURE);
    }

    if(inFile(clave))
    {
        while(archivo.read(reinterpret_cast<char*>(&obj), sizeof(obj)))
        {
            if(getKey(obj) == clave)
            {
                archivo.close();
                return obj;
            }
        }
    }
    else
    {
        archivo.close();
        // Si no se encuentra en ningún lugar, tiro una excepción
        throw runtime_error("Objeto no encontrado");
    }
}
template<class T>
T CacheManager<T>::get(string clave)
{
    T obj; // se asume que la clase va a tener un constructor vacio, de lo contrario esto no es posible
    auto it = cache_data.find(clave);
    
    if(it == cache_data.end())
    {
        try
        {
            obj = getFile(clave);
            insert(clave, obj);
            return obj;
        }
        catch(const runtime_error&e)
        {
            // Vuelvo a tirar la misma excepcion que en getFile 
            throw runtime_error("Objeto no encontrado");
        }
    }
    // Si se encuentra en la caché, actualizo MRU
    it->second.second = ++MRU;
    return it->second.first;

}
template<class T>
void CacheManager<T>::show_cache()
{
    for(auto x = cache_data.begin(); x != cache_data.end(); x++)
        cout<<x->first<<" - "<<x->second.first<<endl;
}