#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
long long int midPoint;
vector <long long int> planetas;
vector <double> resultados;
vector <long long int> cocientes;

long long int suma(vector <double> mira)
{
	double sum = 0;
	for(int i = 0 ; i < planetas.size() ; i++)
	{
		if(planetas[i] < midPoint)
			sum += mira[i];
		else
			sum -= mira[i];
	}
	return sum;
}

long long int cocientes_(long long int enmedio)
{
	vector <double> mira;
	cocientes.clear();
	for(int i = 0 ; i < planetas.size() ; i++)
	{
		cocientes.push_back((1 / fabs((double)planetas[i]/(double)1000 - (double)enmedio/(double)1000))* 1000);
		cout << planetas[i] << " " << enmedio << " " << (long long int)(((1/fabs(((double)planetas[i]/(double)1000 - (double)enmedio/(double)1000)* 1000))) * 1000000) << "\n";
	}
	return suma(cocientes);
}

void binary(long long int ini, long long int fin)
{
	long long int mid;
	midPoint = ini + (fin - ini) / 2;
	while(ini <= fin)
	{
		mid = ini + (fin - ini) / 2;
		if(cocientes_(mid) == 0)
		{
			cout << "\n" << (double)mid /(double)1000 << " ";
			return;
		}
		if(cocientes_(mid) > 0)
			ini = mid + 1;
		else
		{
			fin = mid - 1;
		}
	}
	cout << "\n" << (double)mid /(double)1000 << " ";
	return;
}


int main(void)
{
	long long int numP, auxInt;
	cin >> numP;
	for(int i = 0 ; i < numP ; i++)
	{
		cin >> auxInt;
		planetas.push_back(auxInt * 1000);
	}
	cout << numP  - 1 << "\n";
	cout << fixed;
	cout << setprecision(10);
	for(int i = 0 ; i < numP - 1 ; i++)
		binary(planetas[i], planetas[i + 1]);
	cout << "\n";


	return 0;
}