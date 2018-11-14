#include <vector>
#include <iostream>
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

int main(void)
{
    vector <long long int> primos;
    for(int i = 2 ; i < 100000 ; i++)
        if(isPrimeArreglo(i))
            primos.push_back(i);
    cout << "int primos[" << primos.size() << "] = {";
    for(auto a : primos)
        cout << ", " << a;
    cout << "};";

}


/*
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
*/
