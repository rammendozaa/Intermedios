#include <iostream>
using namespace std;

long long int expoBin(long long int a, long long int b, long long int m)
{
	if (b == 1)
		return a % m;
	if(b == 0)
		return 1 % m;
	if(b % 2 == 0)
	{
		long long int n = (expoBin(a, b/2, m)) % m;
		return (n * n) % m;
	}
	else
	{
		long long int n = (expoBin(a, b - 1, m)) % m;
		return (n * (a % m)) % m;
	}
}

int main(void)
{
    long long int B, P, M, res;
    while(cin >> B >> P >> M)
    {
        res = expoBin(B, P, M);
        cout << res << "\n";
    }
    return 0;
}
