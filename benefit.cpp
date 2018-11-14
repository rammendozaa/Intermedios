#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map <int, int> sacarDiv(long long int n)
{
    map <int, int> primos;
    while(n % 2 == 0)
    {
        primos[2] = primos[2] + 1;
        n = n >> 1;
    }
    for(int i = 3 ; i <= sqrt(n) ; i += 2)
    {
        while(n % i == 0)
        {
            primos[i] = primos[i] + 1;
            n /= i;
        }
    }
    if(n > 2)
        primos[n] = primos[n] + 1;

    return primos;
}


int main(void)
{
    int cases;
    long long int inA, inC, outB;
    cin >> cases;
    while(cases--)
    {
        cin >> inA >> inC;
        if(inC % inA != 0)
            cout << "NO SOLUTION\n";
        else
        {
            map <int, int> primosC, primosA;
            primosC = sacarDiv(inC);
            primosA = sacarDiv(inA);
            outB = 1;
            for(auto a : primosC)
            {
                if(a.second > primosA[a.first])
                    outB *= pow(a.first, a.second);
            }
            //outB = sacarB(inC, inA);
            cout << outB << "\n";
        }
    }

    return 0;
}
