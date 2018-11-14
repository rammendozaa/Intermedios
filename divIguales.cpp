#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector <long long int> criba(long long int a)
{
    vector <long long int> crib(a + 1);
    long long int raiz = sqrt(a);
    for(int i = 4 ; i <= a ; i += 2)
    {
        crib[i] = 2;
    }
    for(int i = 3 ; i <= raiz ; i += 2)
    {
        if(!crib[i])
        {
            for(int j = i * i ; j <= a ; j += i)
            {
                if(!crib[j])
                    crib[j] = i;
            }
        }
    }
    return crib;
}

long long int encontrarDiv(vector <long long int> crib, long long int n)
{
    map <int, int> numeros;
    for(int i = n ; i > 1 ;)
    {
        if(crib[i] == 0)
        {
            numeros[i] = numeros[i] + 1;
            break;
        }
        else
        {
            numeros[crib[i]] = numeros[crib[i]] + 1;
            i = i / crib[i];
        }
    }
    long long int mult = 1;
    for(auto a : numeros)
        mult *= a.second + 1;
    return mult;
}

/*
int factoresDe(int n)
{
    int cuenta = 2;
    for(int i = 2 ; i <= (n / 2) ; i++)
        if(n % i == 0)
            cuenta++;
    return cuenta;
}
*/

int main(void)
{
    int n, num_fact, auxIzq, auxDer, posI, posD;
    cin >> n;
    vector <long long int> cr(10000);
    cr = criba(10000);
    num_fact = encontrarDiv(cr, n);
    posI = 10001;
    for(int i = n - 1 ; i >= 1 ; i--)
    {
        auxIzq = encontrarDiv(cr,i);
        if(auxIzq == num_fact)
        {
            posI = i;
            break;
        }
    }
    posD = 10001;
    for(int i = n + 1 ; i < n + posI + 1 ; i++)
    {
        auxDer = encontrarDiv(cr,i);
        if(auxDer == num_fact)
        {
            posD = i;
            break;
        }
    }
    if(n - posI < posD - n && n - posI > 0)
        cout << posI << "\n";
    else if(n - posI == posD - n)
        (posI > posD) ? cout << posI << "\n" : cout << posD << "\n";
    else
        cout << posD << "\n";

    return 0;
}
