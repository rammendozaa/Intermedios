#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    int root = sqrt(n);
    for(int i = 2 ; i <= root ; i++)
        if(n % i == 0)
            return false;
    return true;
}

int sumaDiv(int n)
{
    int hasta = sqrt(n);
    vector <int> factores;
    for(int i = 1 ; i <= hasta ; i++)
    {
        if(n % i == 0)
        {
            if(i * i == n)
                factores.push_back(i);
            else
            {
                factores.push_back(n/i);
                factores.push_back(i);
            }
        }
    }
    int suma = 0;
    for(auto a : factores)
        suma += a;

    return suma;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int suma, casos = 1;
    while(cin >> suma && suma != 0)
    {
        //cout << suma << "\n";
        if(suma == 1)
            cout << "Case " << casos << ": 1" << "\n";
        else if(suma == 2)
            cout << "Case " << casos << ": -1" << "\n";
        else if(isPrime(suma - 1))
            cout << "Case " << casos << ": " << suma - 1 << "\n";
        else
        {
            //cout << sumaDiv(suma) << "\n";
            int res = 0;
            for(int i = 1002 ; i > 1 ; i--)
            {
                if(sumaDiv(i) == suma)
                {
                    cout << "Case " << casos << ": " << i << "\n";
                    res = 1;
                    break;
                }
            }
            if(res == 0)
                cout << "Case " << casos << ": -1" << "\n";
        }
        casos++;
    }
}
