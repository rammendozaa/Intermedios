#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long int n)
{
    long long root = sqrt(n);
    for(int i = 2 ; i <= root ; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main(void)
{
    long long int n, H;
    cin >> n;
    H = 2 * n;
for(int i = 1 ; ((i * i) + i) < H ; i++)
    {
        long long int ini = 0, fin = H, mid;
        while(ini <= fin)
        {
            mid = ini + (fin - ini) / 2;
            if(((i * i) + i) + ((mid * mid) + mid) == H)
            {
                cout << "YES\n";
                return 0;
            }
            else if(((i * i) + i) + ((mid * mid) + mid) < H)
                ini = mid + 1;
            else
                fin = mid - 1;
        }
    }
    cout << "NO\n";
    return 0;
}
