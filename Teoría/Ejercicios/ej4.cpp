#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int i, j;

    for (i = 1; i <= 10; i++)
    {
        cout<<"\nTabla del  "<<i<<endl;
        for (j = 1; j <= 10; j++)
        {
            cout<<" "<<i*j;
        }
    }
    


    return EXIT_SUCCESS;
}