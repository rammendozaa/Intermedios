#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long int vacasRemaining(vector <long long int> stalls, long long int mid, long long int vacas)
{
	int ult = 0, i;
	while(ult < stalls.size() - 1)// && vacas > 0)
	{
		i = 1;
		while(stalls[ult + i] - stalls[ult] < mid)
		{
			i++;
			if(ult + i >= stalls.size())
				return vacas;
		}
		vacas--;
		if(vacas == 0)
			return 0;
		ult += i;
	}
	return vacas;
}

long long int binary(vector <long long int> stalls, long long int vacas)
{
	long long int mid, ini, fin;
	ini = 0;
	fin = stalls[stalls.size() - 1];
	while(ini <= fin)
	{
		mid = ini + (fin - ini) / 2;
		if(vacasRemaining(stalls,mid, vacas) > 0)
			fin = mid - 1;
		else
			ini = mid + 1;
	}
	return mid + 1;
}

int main(void)
{
	long long int cases, establos, auxInt, vacas;
	cin >> cases;
	while(cases--)
	{
		cin >> establos >> vacas;
		vector <long long int> stalls;
		for(int i = 0 ; i < establos ; i++)
		{
			cin >> auxInt;
			stalls.push_back(auxInt);
		}
		sort(stalls.begin(), stalls.end());
		cout << binary(stalls, vacas) << "\n";
	}

}
