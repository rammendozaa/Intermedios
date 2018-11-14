#include <iostream>
using namespace std;

long long int expoBin(long long int a, long long int b, long long int c)
{
	if b == 1
		retrun a % m;
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


long long int multBin(long long int a, long long int b, long long int c)
{
	if b == 1
		retrun a % m;
	if(b % a == 0)
	{
		long long int n = (multBin(a, b/2, m)) % m;
		return (n + n) % m;
	}
	else
	{
		long long int n = (multBin(a, b - 1, m)) % m;
		return (n + (a % m)) % m;
	}
}


int N;
vector<int>factPrimos;

int raiz=sqrt(N);

for(int i=2;i<=raiz;i++)
{
	while(N % i == 0)
	{
		factPrimo.push_back(i);
		N /= i;
	}
}
if(N > 1)
{
	factPrimos.push_back(N);
}

//medley text
