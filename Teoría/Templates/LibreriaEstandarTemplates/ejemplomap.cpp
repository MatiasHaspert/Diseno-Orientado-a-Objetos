// ejemploMap.cpp

/**
Modo de compilar recomendado
g++ -Wall -std=c++xx -oejemploMap.cpp ejemploMap.cpp
(donde c++xx = al estandar elegido. Ej: -std=c++11 o -std=c++17)
**/

#include<iostream>
#include<string>
#include<map>
using namespace std;

/**
input: dos palabras
return: true si son anagramas / false si no lo son
**/
bool es_anagrama(string, string);

int main() {

	/**
	Ejemplo simple de una posible definición del map
	int: indice 
	string: valor a guardar
	**/
    map<int, string> tempMap = {{1, "Apple",}, {2, "Samsung",},{3, "Nokia",},
                                {4, "BLU",}, {5, "Xiaomi",}, {6, "Cocoa",}};
    /**
	Valido para C++11, usar a auto como tipo de dato, permite que se infiera
	el valor a asignar. en este caso un iterador
	El iterador señala las posiciones del Map, y es asignado como un Par
	por lo tanto tiene first y second
    **/
    auto iter = tempMap.begin();
    /**
    Se recorre con un while
    **/
    cout << "Recorrido con while\n\n";
    while (iter != tempMap.end()) {
        cout << "[" << iter->first << "," << iter->second << "]\n";
        iter++;
    }
    cout << endl;
    /**
	Mismo ejemplo con un for
    **/
    cout<< "Se recorre con un for\n\n";

    for ( iter = tempMap.begin(); iter != tempMap.end(); iter++){
    	cout << "[" << iter->first << "," << iter->second << "]\n";
    }
    cout << endl;

    /**
    Un for simplificado que lo posibilita C++11
    Aqui, no está asignado un puntero iterador
    **/
    cout<< "Se recorre con un for usando auto -- C++11 en adelante\n\n";
    for (auto it: tempMap)
    	cout << "[" << it.first << "," << it.second << "]\n";

    cout << endl;

    /**
	Ejemplo mas elegante, es convirtiendo la salida del Map en un 
	Pair sin uso de iterador.
	Esto es valido desde C++17
    **/
    cout<< "Se recorre con un for usando auto formando un Pair -- "
    	<< "valido para C++17\n\n";
    for (auto [key, value] : tempMap) {
        cout << "[" << key << "," << value << "]\n";
    }
    cout << endl;

    /**
	Para trabajar con los datos específicos, podemos usar el índice en forma
	directa
    **/
    cout << "Acceso a un dato segun posicion\n\n";
    cout << "En la posición 1 encontramos: " << tempMap[1] << endl;

    /**
	De modo similar, podemos agregar o modificar información
    **/
    tempMap[1] = "Iphone";
    tempMap[7] = "LG";
    cout<< "Se recorre el Map para ver los cambios\n\n";
    	
    for (auto [key, value] : tempMap) {
        cout << "[" << key << "," << value << "]\n";
    }
    cout << endl;

    /**
	Ejemplo de uso de Map como diccionario de ocurrencia
    **/
    string p1 = "altisonancia";
    string p2 = "nacionalista";
    if (es_anagrama(p1, p2))
    	cout << "es un anagrama\n";
    else
    	cout << "no es anagrama\n";

    p2 = "nasionalista";
    if (es_anagrama(p1, p2))
    	cout << "es un anagrama\n";
    else
    	cout << "no es anagrama\n";

    return 0;

}

/**
algoritmo
1. Declarar un map M con llave caracter y valor entero
2. Usar el mapa para determinar la frecuencia de cada letra en p1
3. Si len(p1) != len(p2) return false
3. Por cada letra c de p2:
4.    Si c no está en M o el valor de M[c] == 0, devolver false
5.    Else: restar 1 al valor de M[c]
6. return true
**/
bool es_anagrama(string p1, string p2){
	
	if (p1.length() != p2.length())
		return false;

	map<char, int> M;

	for (auto it: p1)		
		M[it]++;
		
	for (auto it: p2){
		if (M[it] != 0)
			M[it]--;
		else
			return false;
	}
	return true;

}