#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
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

vector<pair<int, int> > factoresFact(int n, vector <int> primos)
{
    vector <pair<int, int> > factores;
    for(int i = 0 ; i < primos.size() ; i++)
    {
        if(n < primos[i])
            break;
        int p = primos[i];
        int veces = n / p;
        while(primos[i] <= n / p)
        {
            p *= primos[i];
            veces += n / p;
        }
        factores.push_back(make_pair(primos[i], veces));
    }
    return factores;
}

int main(void)
{
    int n;
    while(cin >> n && n != 0)
    {
        vector <int> primos;
        vector <pair <int, int> > res;
        for(int i = 2 ; i < 10000 ; i++)
            if(isPrimeArreglo(i))
                primos.push_back(i);
        res = factoresFact(n, primos);
        string ene = to_string(n);
        if(ene.length() == 1)
            cout << "  " << ene << "! =";
        else if(ene.length() == 2)
            cout << " " << ene << "! =";
        else
            cout << "100! =";
        int contador = 0;
        for(auto a : res)
        {
            string auxS = to_string(a.second);
            if(auxS[0] == '0' && auxS.length() == 1)
                cout << "   ";
            else if(auxS.length() == 1)
                cout << "  " << auxS;
            else if(auxS.length() == 2)
                cout << " " << auxS;
            else
                cout << auxS;
            contador++;
            if(contador == 15 && res.size() > 15)
                cout << "\n" << "      ";
            //    break;
        }
        cout << "\n";
    }
    return 0;
}
//-
