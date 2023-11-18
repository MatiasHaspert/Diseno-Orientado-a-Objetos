#ifndef __MATRIZ_H
#define __MATRIZ_H

#include <iostream>

using namespace std;

template<class T> 
class matriz 
{
	T **m;
	unsigned xmax, ymax;
    public:
	matriz(const matriz &mm)
    {
        xmax = mm.xmax;
        ymax = mm.ymax;

        m = new T*[xmax];
        for (unsigned i = 0; i < xmax; i++)
        {
            m[i] = new T[ymax];
        }
        
        for (unsigned i = 0; i < xmax; i++)
        {
            for (unsigned j = 0; j < ymax; i++)
            {
                m[i][j] = mm.m[i][j];
            }
        }   
    }
	matriz(unsigned xmax, unsigned ymax) : xmax(xmax), ymax(ymax)
    {
        m = new T*[xmax];
        for(unsigned i = 0; i < xmax; i++) m[i] = new T[ymax];
    }
	~matriz()
    {
        for (unsigned i = 0; i < xmax; ++i)
        {
			delete m[i];
		}
		delete m;
    }
	unsigned maxx() const { return xmax; }
	unsigned maxy() const { return ymax; }
	T *operator[](unsigned y) const { return m[y]; }
    template<class U>
    friend ostream& operator<<(ostream &os, matriz<U> &mm);
};

template<class U>
ostream& operator<<(ostream &os, matriz<U> &mm)
{
    for (unsigned i = 0; i < mm.xmax; i++)
    {
        for(unsigned j = 0; j < mm.ymax; j++)
        {
            cout<<" "<<mm[i][j];
        }
        cout<<endl;
    }

    return os;
}

void f(matriz<int>&);
#endif