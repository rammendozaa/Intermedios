#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        int amigos, cajas, auxI, chocolates = 1, res = 0;
        cin >> amigos >> cajas;
        for(int i = 0 ; i < cajas ; i++)
        {
            int K;
            cin >> K;
            chocolates = 1;
            for(int j = 0 ; j < K ; j++)
            {
                cin >> auxI;
                chocolates *= (auxI % amigos);
                chocolates %= amigos;
            }
            res += chocolates;
        }
        cout << res % amigos << "\n";
    }
    return 0;
}
