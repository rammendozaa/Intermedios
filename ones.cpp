#include <iostream>
using namespace std;

int main(void)
{
    int entrada;
    while(cin >> entrada && entrada != 0)
    {
        if(entrada == 1)
            cout << "1\n";
        else
        {
            long long int unos, rem = 1;
            int contador = 1;
            while(rem != 0)
            {
                unos = (rem * 10) + 1;
                rem = unos % entrada;
                contador++;
            }
            cout << contador << "\n";
        }
    }
    return 0;
}
