#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int prueba(vector <int> vacas, int mid, int vacasN)
{
    int ini, fin;
    ini = vacas[0];
    fin = vacas[vacas.size() - 1];
    int inicial = 0, siguiente = 1, vacasLeft = vacasN - 1;
    while(siguiente < vacas.size() && vacasLeft > 0)
    {
        while(vacas[siguiente] - vacas[inicial] < mid && siguiente < vacas.size())
            siguiente++;
        if(siguiente < vacas.size())
            vacasLeft--;
        inicial = siguiente;
        siguiente = inicial + 1;
    }
    return vacasLeft;
}

void bus(vector <int> vacas, int vacN)
{
    int ini, fin, mid, maxD = -1, vacasR;
    ini = vacas[0];
    fin = vacas[vacas.size() - 1];
    while(ini <= fin)
    {
        mid = ini + (fin - ini) / 2;
        vacasR = prueba(vacas, mid, vacN);
        if(vacasR > 0)
            fin = mid - 1;
        else
        {
            if(vacasR == 0)
                maxD = max(mid, maxD);
            ini = mid + 1;
        }
    }
    cout << maxD << "\n";
}


int main(void)
{
    int establos, vacas, auxI, cases;
    cin >> cases;
    while(cases--)
    {
        vector <int> vac;
        cin >> establos >> vacas;
        for(int i = 0 ; i < establos ; i++)
        {
            cin >> auxI;
            vac.push_back(auxI);
        }
        sort(vac.begin(), vac.end());
        bus(vac, vacas);
    }
    return 1;
}
