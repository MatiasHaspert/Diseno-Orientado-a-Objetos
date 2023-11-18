#include <iostream>

using namespace std;

class Vec
{
    private:
        float v1, v2, v3, v4;
    public:
    Vec()
    {
        v1 = 0.0;
        v2 = 0.0;
        v3 = 0.0;
        v4 = 0.0;
    }
    Vec(float num1, float num2, float num3, float num4)
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
    void printV(Vec v)
    {
        cout<<"\nEl vector es ["<<v.v1<<", "<<v.v2<<", "<<v.v3<<", "<<v.v4<<"]"<<endl;
    }
    void ingresa_datos (Vec *v)
    {
	    float n1, n2, n3 ,n4;
	    cout<<"\nIngrese 1º componente: ";
	    cin>>n1;
	    v->setv1(n1);
	    cout<<"\nIngrese 2º componente: ";
	    cin>>n2;
	    v->setv2(n2);
	    cout<<"\nIngrese 3º componente: ";
	    cin>>n3;
	    v->setv3(n3);
	    cout<<"\nIngrese 4º componente: ";
	    cin>>n4;
    	v->setv4(n4);
    }
};
