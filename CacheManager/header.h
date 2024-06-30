#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

//Dato a guardar en el archivo de longitud fija
template <class T>
class DatoFile
{
private:
    int key; //Se va almacenar un entero porque trabajar con string genera problemas.
    T obj;

public:
    DatoFile(): key(0), obj(T()){};
    DatoFile(string _key, T _obj) : key(stoi(_key)), obj(_obj){};
    ~DatoFile(){};

    string getKey()
    {
        return to_string(key);
    }

    T getObj()
    {
        return obj;
    }
};


template <class T>
class CacheManager
{
private:
    
    int capacity;
    map <string, pair <T, int>> cache_data; // <Clave, <Obj, Indice de Uso>>
    int MRU = 1;
    const string nameFile = "disco.dat";
    
    bool write_file (string key, T obj);
    T get_file(string key);
    bool update_file(string key, T obj);
    bool keyInFile(string key);

public:

    CacheManager(int); // recibe la capacidad en el int
    ~CacheManager(){};

    void insert (string key, T obj);
    T get (string key);
    void show_cache();
    string getLRU ();
    void update_cache(string key, T obj);
    void show_memory();  
};

template <class T>
void CacheManager <T>:: show_memory()
{
    ifstream file(nameFile, ios::in | ios::binary);

    if(!file)
    {
        cerr<<"File failure";
        exit(EXIT_FAILURE);
    }

    DatoFile <T> datoRead;
    cout<<endl<<"Memory:";

    while (file && file.read(reinterpret_cast<char *> (&datoRead), sizeof(datoRead)))
    {
        cout<<endl<<"Key: "<<datoRead.getKey()<<" Object: "<<datoRead.getObj();
    }

    file.close();   
}

template <class T>
bool CacheManager <T>::keyInFile(string key)
{
    ifstream file(nameFile, ios::in | ios::binary);

    if(!file)
    {
        cerr<<"File failure";
        exit(EXIT_FAILURE);
    }

    DatoFile <T> datoRead;   

    while (file && file.read(reinterpret_cast<char *> (&datoRead), sizeof(datoRead)))
    {
        if(datoRead.getKey() == key)
        {    
            file.close();
            return true;
        }
    }

    file.close();    
    return false;
}

/*
Habia planteado esta funcion mas eficiente para actualizar el objeto en el archivo, pero al insertar otra vez el mismo dato me lo rompe
no pude solucionarlo

template< class T>
bool CacheManager <T>::update_file(string key, T obj)
{

    fstream file(nameFile, ios::in | ios::out | ios::binary);
    
    if(!file)
    {
        cerr<<"File failure";
        exit(EXIT_FAILURE);
    }
    
    DatoFile <T> d(key, obj);
    file.seekp(stoi(key) * sizeof(d)); // Me posiciono en la key a actualizar
    file.write(reinterpret_cast<const char*> (&d), sizeof(d));
    file.close();
    return true;
}
*/

template< class T>
bool CacheManager <T>::update_file(string key, T obj)
{
    //Voy a actualizar el objeto volviendo a escribir todos los datos menos el de la key a actualizar
    fstream file(nameFile, ios::in | ios::out | ios::binary);
    
    if(!file)
    {
        cerr<<"File failure";
        exit(EXIT_FAILURE);
    }
    
    vector<DatoFile<T>> datos;
    
    DatoFile <T> datoRead;   

    while (file && file.read(reinterpret_cast<char *> (&datoRead), sizeof(datoRead)))
    {
        if(datoRead.getKey() != key)
        {
            datos.push_back(datoRead);    
        }
    }

    
    file.close();
    file.open(nameFile, ios::out | ios::binary | ios::trunc); // Limpio el archivo
    
    if(!file)
    {
        cerr<<"File failure";
        exit(EXIT_FAILURE);
    }

    for (auto dato : datos)
    {
        file.write(reinterpret_cast<const char*> (&dato), sizeof(dato));
    }
    
    file.close();
    return true;
}

template <class T>
bool CacheManager <T>::write_file(string key , T obj)
{
    //Busco la key en el archivo, si existe la borro
    if(keyInFile(key))
    {
        update_file(key, obj);
    }     

    DatoFile<T> d(key,obj);
    
    ofstream file(nameFile, ios::app | ios::binary);
    
    if(!file)
    {
        cerr<<"File failure";
        exit(EXIT_FAILURE);
    }        
    
    // Inserto el nuevo dato en el final
    file.write(reinterpret_cast<const char*> (&d), sizeof(d));
    file.close();
    return true;
}

template <class T>
T CacheManager <T>::get_file(string key)
{
    ifstream file(nameFile, ios::in | ios::binary);

    if(!file)
    {
        cerr<<"File failure";
        exit(EXIT_FAILURE);
    }

    DatoFile <T> datoRead;
    
    while (file && file.read(reinterpret_cast<char *> (&datoRead), sizeof(datoRead)))
    {
        if(datoRead.getKey() == key)
        {
            update_cache(datoRead.getKey(), datoRead.getObj());
            
            file.close();
            
            return datoRead.getObj();
        }
    }
    
    file.close();
    
    cerr<<endl<<"Object not exist"<<endl;
    T nullT; //Devuelvo un valor predeterminado del objeto
    return nullT;
}

template <class T>
string CacheManager <T>::getLRU()
{
    auto it = cache_data.begin();
    
    string keyLRU = it->first;
    int LRU = it->second.second;

    while(it != cache_data.end())
    {
        if(it->second.second < LRU)
        {
            LRU = it->second.second;
            keyLRU = it->first;
        }

        it++;
    }

    return keyLRU;
}


template <class T>
void CacheManager <T>::show_cache()
{
    cout<<endl<<"Cache:"<<endl;
    if(!cache_data.empty())
    {
        for(auto& it : cache_data)
            cout << it.second.first<<endl;
    }
    else
    {
        cout<<"Cache is empty";
    }
}

template <class T>
CacheManager <T>::CacheManager (int cap)
{
    capacity = cap;
}

template <class T>
void CacheManager <T>::insert (string key, T obj) 
{    
    //Inserto o actualizo el objeto en cache
    update_cache(key, obj);

    //Inserto o actualizo el objeto en el archivo
    write_file(key, obj);
}   


template <class T>
void CacheManager <T> ::update_cache(string key, T obj)
{
    auto it = cache_data.find(key);

    //Si la cache esta llena y el nuevo obj no se encuentra en la cache
    if(cache_data.size() == capacity && it == cache_data.end()) 
    {
        //Borro el LRU de la cache
        cache_data.erase(getLRU());
        
    }
    cache_data[key] = make_pair(obj, MRU);
    MRU++;
}

template <class T>
T CacheManager <T>::get(string key)
{
    auto it = cache_data.find(key);

    //Busco el objeto en la cache
    if(it != cache_data.end())
    {
        update_cache(it->first, it->second.first);
        return it->second.first;
    }

    //Si no esta en cache lo busco en el archivo
    return get_file(key); 
}
