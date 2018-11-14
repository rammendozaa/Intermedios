#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector <int> Criba(int n)
{
    int raiz = sqrt(n);
    vector <int> criba(n + 1);
    for(int i = 4 ; i <= n ; i += 2)
        criba[i] = 2;
    for(int i = 3 ; i <= raiz ; i += 2)
        if(!criba[i])
            for(int j = i * i ; j <= n ; j += i)
                if(!criba[j])
                    criba[j] = i;
    return criba;
}

int main(void)
{
    int entrada;
    vector <int> crib = Criba(1000000);

    while(cin >> entrada && entrada != 0)
    {
        int pos = entrada, auxI = entrada;
        pos--;
        while(crib[pos] != 0 || crib[auxI] != 0)
        {
            pos--;
            auxI = entrada - pos;
        }
        cout << entrada << " = " << auxI << " + " << pos << "\n";
    }
}
