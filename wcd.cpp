#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

vector <long long int> sacarPrimos(long long int a)
{
    long long int raiz = sqrt(a);
    vector <long long int> primos;
    for(int i = 2 ; i <= raiz ; i++)
    {
        while(a % i == 0)
        {
            primos.push_back(i);
            a /= i;
        }
    }
    if(a > 1)
        primos.push_back(a);
    return primos;
}

int main(void)
{
    int numeros;
    cin >> numeros;
    vector <pair <long long int, long long int> > valores;
    long long int auxA, auxB;
    while(numeros--)
    {
        cin >> auxA >> auxB;
        valores.push_back(make_pair(auxA, auxB));
    }
    vector <long long int> fpA = sacarPrimos(valores[0].first);
    vector <long long int> fpB = sacarPrimos(valores[0].second);
    long long int factorA, factorB;
    vector <long long int> posibles;
    for(auto b : fpA)
    {
            for(auto a : valores)
            {
                if(a.first % b == 0 || a.second % b == 0)
                    factorA = b;
                else
                {
                    factorA = -1;
                    break;
                }
            }
            if(factorA != -1)
                posibles.push_back(factorA);
    }
    for(auto b : fpB)
    {
            for(auto a : valores)
            {
                if(a.first % b == 0 || a.second % b == 0)
                    factorB = b;
                else
                {
                    factorB = -1;
                    break;
                }
            }
            if(factorB != -1)
                posibles.push_back(factorB);
    }
    (posibles.size() == 0) ? cout << "-1\n" : cout << posibles[0] << "\n";
    return 0;
}
