#include "matriz.h"

int main()
{

	matriz<int> a(10, 10);

	matriz<char> c(10, 10);

	int i, j;

	for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            a[i][j]=i+j;
            c[i][j]='A'+i+j;
		}
    }

	cout<<"\nMatriz A:"<<endl;
	f(a);

	cout<<"\nMatriz C:"<<endl;
	cout<<c<<'\n';

	return 0;

}

void f(matriz<int> &x)
{	
    cout<<x<<'\n';

	x[5][5]=123;

	cout<<"Matriz A, luego de la funcion:"<<endl;
	cout<<x<<'\n';
}