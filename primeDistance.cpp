#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(long long int n)
{
    long long int root = sqrt(n);
    for(int i = 2 ; i <= root ; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main(void)
{
    long long int L, U;
    while(cin >> L >> U)
    {
        long long int minDis = 100001, maxDis = -1;
        vector <long long int> losPrimos;
        if(L == U)
            cout << "There are no adjacent primes.\n";
        else
        {
            if(L == 1)
                L++;
            for(int i = L ; i <= U ; i++)
                if(isPrime(i))
                    losPrimos.push_back(i);
    /*        if(losPrimos.size() == 1 || losPrimos.size() == 0)
                cout << "There are no adjacent primes.\n";
            else
            {
                long long int minI, minD, maxI, maxD;
                for(int i = losPrimos.size() - 1 ; i > 0 ; i--)
                {
                    if(losPrimos[i] - losPrimos[i - 1] <= minDis)
                    {
                        minI = losPrimos[i - 1];
                        minD = losPrimos[i];
                        minDis = minD - minI;
                    }
                    if(losPrimos[i] - losPrimos[i - 1] >= maxDis)
                    {
                        maxI = losPrimos[i - 1];
                        maxD = losPrimos[i];
                        maxDis = maxD - maxI;
                    }
                }
                cout << minI << "," << minD << " are closest, " << maxI << "," << maxD << " are most distant.\n";
            }
            */
        }
    }
    return 0;
}

/*
int main(void)
{
    long long int L, U;
    while(cin >> L >> U)
    {
        long long int minDis = 100001, maxDis = -1;
        vector <long long int> losPrimos;
        if(L == U)
            cout << "There are no adjacent primes.\n";
        else
        {
            if(L == 1)
                L++;
            for(int i = L ; i <= U ; i++)
                if(isPrime(i))
                    losPrimos.push_back(i);
            if(losPrimos.size() == 1 || losPrimos.size() == 0)
                cout << "There are no adjacent primes.\n";
            else
            {
                long long int minI, minD, maxI, maxD;
                for(int i = losPrimos.size() - 1 ; i > 0 ; i--)
                {
                    if(losPrimos[i] - losPrimos[i - 1] <= minDis)
                    {
                        minI = losPrimos[i - 1];
                        minD = losPrimos[i];
                        minDis = minD - minI;
                    }
                    if(losPrimos[i] - losPrimos[i - 1] >= maxDis)
                    {
                        maxI = losPrimos[i - 1];
                        maxD = losPrimos[i];
                        maxDis = maxD - maxI;
                    }
                }
                cout << minI << "," << minD << " are closest, " << maxI << "," << maxD << " are most distant.\n";
            }
        }
    }
    return 0;
}
*/
