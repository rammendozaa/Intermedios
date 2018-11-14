/*
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <map>
using namespace std;

long long int gcd(long long int a, long long int b)
{
  if(b == 0)
  	return a;
  else
  	gcd(b, a % b);
}

long long int lcm(vector <long long int> numeros)
{
	long long int res = numeros[0];
    for(int i = 1 ; i < numeros.size() ; i++)
        res = (((numeros[i] * res)) / (gcd(numeros[i], res)));
    return res;
}

long long int lcmDos(long long int a, long long int b)
{
    return (a * b) / gcd(a, b);
}

long long int sacarDiv(long long int n)
{
    map <long long int, long long int> primos;
    vector <long long int> multiplos;
    long long int entrada = n;
    while(n % 2 == 0)
    {
        primos[2] = primos[2] + 1;
        n = n >> 1;
    }
    for(long long int i = 3 ; i <= sqrt(n) ; i += 2)
    {
        while(n % i == 0)
        {
            primos[i] = primos[i] + 1;
            n /= i;
        }
    }
    if(n > 2)
        primos[n] = primos[n] + 1;

//    for(auto a : primos)
//        cout << a.first << " " << a.second << "\n";
//    cout << "\n";
    for(auto a : primos)
        multiplos.push_back(a.first);

    long long int eleceme = entrada;
    unordered_set <long long int> lcms;
    if(multiplos.size() > 1)
    {
        eleceme = lcm(multiplos);//saca el lcm de todos los numeros falta el individual
        lcms.insert(eleceme);
        for(int i = 0 ; i < multiplos.size() ; i++)
            for(int j = i + 1 ; j < multiplos.size() ; j++)
                lcms.insert(lcmDos(multiplos[i], multiplos[j]));
    }
//    for(auto a : lcms)
//        cout << a << "\n";
//    cout << "\n";
    int res = 0;
    for(auto a : multiplos)
        res += ((entrada / a) - 1);


    int resFinal = (entrada - 1) - res;
//    cout << resFinal << "\n";
    for(auto a : lcms)
    {
        long long int divi = (long long int)(entrada / a);
        if(a < entrada && divi > 0)
            resFinal += (divi - 1);
    }

    return resFinal;

    if(eleceme < entrada)
        return (entrada - 1) - res + ((entrada / eleceme) - 1);
    else
        return (entrada - 1) - res;

}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int entrada;
    while(cin >> entrada && entrada != 0)
    {
        if(entrada == 1)
            cout << 0 << "\n";
        else
            cout << sacarDiv(entrada) << "\n";
    }
}
*/
// C program to calculate Euler's Totient Function
#include <bits/stdc++.h>

long long int phi(long long int n)
{
	long long int res = n;
    for (int p = 2; p * p <= n; ++p)
    {
	    if (n % p == 0)
        {
		    while (n % p == 0)
				n /= p;
			res -= res / p;
		}
	}
	if (n > 1)
		res -= res / n;
	return res;
}

// Driver program to test above function
int main()
{
	long long int n;
    scanf("%lld", &n);
	//while(scanf("%lld", &n) != EOF)
    while(n != 0)
    {
        if(n == 1)
            printf("1\n");
        else
            printf("%lld\n", phi(n));
        scanf("%lld", &n);
    }
	return 0;
}
