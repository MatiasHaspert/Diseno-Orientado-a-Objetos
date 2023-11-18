#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
Sea un grafo G = (V, E)
*/
class grafo{
	
	vector<char> V;
	vector<pair<pair<char, char>, int>> E;
public:
	grafo(){}
	~grafo(){}

	void insertar_vertice(const char&);
	void insertar_arista(const char&, const char&, const int&);

	friend ostream& operator <<(ostream&, grafo);
};

void grafo::insertar_vertice(const char& vertice){
	V.push_back(vertice);
}

void grafo::insertar_arista(const char& vertice1, const char& vertice2, const int& costo){
	
	E.push_back(make_pair(make_pair(vertice1, vertice2), costo));
}

ostream& operator <<(ostream& os, grafo G){

	os << "El grafo es: \n";
	for(auto x: G.E)
		os << x.first.first << " - " << x.first.second << ": costo = " << x.second << endl;

	return os;
}

int main(){
	grafo G;

	G.insertar_vertice('a');
	G.insertar_vertice('b');
	G.insertar_vertice('c');
	G.insertar_vertice('d');

	G.insertar_arista('a', 'b', 52 );
	G.insertar_arista('a', 'c', 15 );
	G.insertar_arista('a', 'd', 5 );
	G.insertar_arista('b', 'c', 40 );
	G.insertar_arista('a', 'd', 25 );
	G.insertar_arista('c', 'd', 1 );

	cout << G;
	return 0;
}