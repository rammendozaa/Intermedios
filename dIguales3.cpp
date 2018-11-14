#include <iostream>
#include <vector>
using namespace std;

void todosDiv(int lim, vector <int> &divisores)
{
    divisores.resize(lim + 1,0);
    for(int i = 1 ; i <= lim ; ++i)
        for(int j = i ; j <= lim ; j += i)
            divisores[j]++;

}

int main(void)
{
    int n, lim = 110000;
    cin >> n;
    vector <int> divisores;
    todosDiv(lim + 1,divisores);
    int abajo = n - 1, arriba = n + 1, res;
    while(true)
    {
        if(arriba <= lim && divisores[arriba] == divisores[n])
        {
            res = arriba;
            break;
        }
        if(abajo > 0 && divisores[abajo] == divisores[n])
        {
            res = abajo;
            break;
        }
        ++arriba;
        --abajo;
    }
    cout << res << "\n";
    return 0;
}
