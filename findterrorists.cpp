#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int numFact(int n)
{
    int raiz = sqrt(n);
    int contador = 0;
    for(int i = 1 ; i <= raiz ; i++)
    {
        if(n % i == 0)
            contador += 2;
        if(i * i == n)
            contador--;
    }
    return contador;
}

bool isPrime(int n)
{
    if(n == 1)
        return false;
    int raiz = sqrt(n);
    for(int i = 2 ; i <= raiz ; i++)
        if(n % i == 0)
            return false;
    return true;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cases, L, H;
    cin >> cases;
    while(cases--)
    {
        cin >> L >> H;
        if(L == H)
        {
            if(isPrime(numFact(L)))
                cout << L << "\n";
            else
                cout << "-1\n";
        }
        else
        {
            bool uno = false;
            int i = L;
            if (i == 1)
                i++;
            while(!isPrime(numFact(i)) && i <= H)
            {
                i++;
            }
            if(i > H)
                uno = false;
            else
            {
                uno = true;
                cout << i;
                i++;
            }
            while(i <= H)
            {
                if(isPrime(numFact(i)))
                {
                    cout << " " << i;
                    uno = true;
                }
                i++;
            }
            if(!uno)
                cout << "-1\n";
            else
                cout << "\n";
        }
    }
    return 0;
}
