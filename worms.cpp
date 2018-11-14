#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;


/*
void binary(vector <int> buscar, int buscado)
{
    int ini = 1, fin = buscar.size() - 1, mid;
    while(ini <= fin)
    {
        mid = (ini + fin) / 2;
        if(buscado >= buscar[mid - 1] + 1 && buscado <= buscar[mid])
        {
            cout << mid + 1 << "\n";
            return;
        }
        else if(buscado < buscar[mid])
            fin = mid - 1;
        else
            ini = mid + 1;
    }
    cout << mid << "\n";
    return;
}
*/


int main(void)
{
    int piles, auxI, buscados;
    cin >> piles;
    vector <int> gusanos(piles + 1);
    gusanos[0] = 0;
    for(int i = 1 ; i <= piles ; i++)
    {
        cin >> auxI;
        gusanos[i] = gusanos[i - 1] + auxI;
    }
    cin >> buscados;
    vector <int> busca(buscados);
    for(int i = 0 ; i < buscados ; i++)
    {
        cin >> auxI;
        busca[i] = auxI;
    }
    for(auto a : busca)
        cout << lower_bound(gusanos.begin(), gusanos.end(), a) - gusanos.begin() << "\n";;
    return 0;
}
