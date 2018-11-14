#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
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

long long int sacarDiv(long long int n)
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

    int res = 0;
    for(auto a : primos)
        res += a.second;
    return res;
}


int main(void)
{
    int n;
    //cout << pow(2, (2 * 2) - 1) - pow(2, 2 - 1) << "aqui\n";
    while(cin >> n && n != 0)
    {
        if(!isPrimeArreglo(n))
            cout << "Given number is NOT prime! NO perfect number is available.\n";
        else
        {
            long long int num = pow(2, (2 * n) - 1) - pow(2, n - 1);
            int factores = sacarDiv(num);
            if(factores == n)
                cout << "Perfect: " << num << "!\n";
            else
                cout << "Given number is prime. But, NO perfect number is available.\n";
        }
    }
    return 0;
}
