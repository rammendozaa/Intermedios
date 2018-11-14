#include <iostream>
#include <vector>
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
    long long int entrada, n;
    cin >> entrada;
    if(isPrime(entrada))
    {
        cout << "1\n" << entrada << "\n";
        return 0;
    }
    long long int nextPrime = entrada, resta;
    while(!isPrime(nextPrime))
        nextPrime--;
    resta = entrada - nextPrime;
    if(isPrime(resta))
        cout << "2\n" << nextPrime << " " << resta << "\n";
    else
    {
        long long int pos = resta, auxI = resta;
        pos--;
        while(!isPrime(pos) || !isPrime(auxI))
        {
            pos--;
            auxI = resta - pos;
        }
        cout << "3\n" << pos << " " << auxI << " " << nextPrime << "\n";
    }
}
