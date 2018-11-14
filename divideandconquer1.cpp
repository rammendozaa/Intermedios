/*

Mendoza Ramírez Álvaro (rammendozaa)
Solución para problema Divide and Conquer 1

M. en C. Franco Martinez Edgardo Adrián
Análisis de Algoritmos
Grupo 3CM3

*/

#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    long long int cantidadNum, auxI, maxMax = -1e9, maxHastaAhora = 0;
    cin >> cantidadNum;
    for(int i = 0 ; i < cantidadNum ; i++)
    {
        cin >> auxI;
        maxHastaAhora = maxHastaAhora + auxI;
        if(maxMax < maxAhora)
            maxMax = maxAhora;
        if(maxAhora < 0)
            maxAhora = 0;
    }
    cout << maxMax << "\n";
    return 0;
}
