#include <iostream>
using namespace std;

long long int expoBin(long long int a, long long int b, long long int m)
{
	if (b == 1)
		return a % m;
	if(b % a == 0)
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
    long long int x, y, n, z, igno;
    int cases;
    cin >> cases;
    while(cases--)
    {
        cin >> x >> y >> n;
        z = expoBin(x, y, n);
        cout << z << "\n";
    }
	cin >> igno;
	return 0;
}
