#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrimeArreglo(long long int n)
{
    long long int root = sqrt(n);
    for(int i = 2 ; i <= root ; i++)
        if(n % i == 0)
            return false;
    return true;
}

bool isPrime(vector <long long int> primos, int buscado)
{
    int ini = 0, fin = 9592, mid;
    if(buscado == 2 || buscado == 3 || buscado == 5 || buscado == 7)
        return true;
    else
    {
        while(ini <= fin)
        {
            mid = (ini + fin) >> 1;
            if(primos[mid] == buscado)
                return true;
            else if(primos[mid] < buscado)
                ini = mid + 1;
            else
                fin = mid - 1;
        }
    }
    return false;
}

int main(void)
{
    string auxS;
    vector <long long int> primosAux;
    for(int i = 2 ; i < 100000 ; i++)
        if(isPrimeArreglo(i))
            primosAux.push_back(i);
    while(cin >> auxS && (auxS[0] != '0' || auxS.length() != 1))
    {
        long long int izq = 0, der = 0, maxPrime = -1, auxI = 0;
        while(der < auxS.length() && izq < auxS.length())
        {
            if(izq == der)
            {
                auxI = auxS[izq] - '0';
                if(isPrime(primosAux, auxI))
                    maxPrime = max(maxPrime, auxI);
                der++;
                while(der - izq <= 6)// && (der < auxS.length() && izq < auxS.length()))
                {
                    auxI = stoull(auxS.substr(izq, der - izq));
                    if(isPrime(primosAux, auxI))
                        maxPrime = max(maxPrime, auxI);
                    der++;
                }
            }
            izq++;
            der = izq;
        }
        cout << maxPrime << "\n";
    }

}
