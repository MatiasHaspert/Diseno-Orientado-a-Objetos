#include <string>
#include <iostream>

using namespace std;
int cmp_nocase(string s, string s2);
int main ()
{
    string s = "abcde", s2 = "abcdf", s3 = "abc";

    cout << "usamos compare..." << endl;
    if (!s.compare(s2)) // como retorna 0 si son iguales, usamos el !
        cout << "son iguales" << endl;
    else
        cout << "son distintas" << endl;

    cout << "usamos == ..." << endl;
    if (s == s2)
        cout << "son iguales" << endl;
    else
        cout << "son distintas" << endl;
    
    cout << "usamos compare para comparar los 3 primeros\n"<< "caracteres con s2" << endl;
    if (s.compare(0,3,s2) == 0)
        cout << "son iguales" << endl;
    else
        cout << "son diferentes\n";

    cout << "usamos compare para comparar los 3 primeros\n"<< "caracteres con s3" << endl;
    if (s.compare(0,3,s3) == 0)
        cout << "son iguales" << endl;
    else
        cout << "son diferentes\n";

    return 0;

}

int cmp_nocase(string s, string s2)
{
    string::const_iterator p = s.begin();
    string::const_iterator p2 = s2.begin();

    while(p != s.end() && p2 != s2.end())
    {
        if (toupper(*p) != toupper(*p2) )
           return (toupper(*p) < toupper(*p2)) ? -1 : 1;

        ++p;
        ++p2;
    }

    return (s2.size() == s.size()) ? 0 : (s.size() < s2.size()) ? -1 : 1;
}