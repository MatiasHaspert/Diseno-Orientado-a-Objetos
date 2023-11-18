#include<iostream>
#include<string>

using namespace std;

class complejo{
	int real;
	int imaginario;
public:
	complejo(){real = imaginario = 0;}
	complejo(int r, int i):real{r}, imaginario{i}{}

	int get_real(){return real;}
	int get_imaginario(){return imaginario;}

	complejo suma(complejo );
	string mostrar();
};


complejo complejo::suma(complejo c){
	// sumo parte real
	int r = real + c.get_real();
	// sumo parte imaginaria
	int i = imaginario + c.get_imaginario();

	return complejo(r, i);
}

string complejo::mostrar(){
	string complex = "(" + to_string(real);
	if (imaginario < 0)
		complex = complex + " - " + to_string(imaginario) + "i)";
	else
		complex = complex + " + " + to_string(imaginario) + "i)";
	return complex;
}

int main (){
	complejo c1;
	complejo c2(4, 6);

	complejo c3 = c1.suma(c2);
	cout << c3.mostrar();
	return 0;
}