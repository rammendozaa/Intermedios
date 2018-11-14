#include <iostream>
#include <vector>
using namespace std;
vector <int> canicas;
vector <int> queries;
	
int itbinarySearch(int valor)
{
	int ini = 0, fin = canicas.size() - 1, res = -1, mid;
	bool found = false;;
	while(ini <= fin)
	{
		mid = (fin + ini) / 2;
		if(canicas[mid] < valor)
			ini = mid + 1;
		else
		{
			fin = mid - 1;
			if(canicas[mid] == valor)
				res = mid;
			
		}
	}
	return res;	
}

void merge(int ini, int mid, int fin)
{
	int i, j, k;
	int tam1 = mid - ini + 1;
	int tam2 = fin - mid;

	vector <int> izq(tam1);
	vector <int> der(tam2);
	for(i = 0 ; i < tam1 ; i++)
		izq[i] = canicas[ini + i];
	for(j = 0 ; j < tam2 ; j++)
		der[j]  = canicas[mid + 1 + j];
	i = 0;
	j = 0;
	k = ini;
	while(i < tam1 && j < tam2)
	{
		if(izq[i] <= der[j])
		{
			canicas[k] = izq[i];
			i++;
		}
		else
		{
			canicas[k] = der[j];
			j++;
		}
		k++;
	}
	while(i < tam1)
	{
		canicas[k] = izq[i];
		i++;
		k++;
	}
	while(j < tam2)
	{
		canicas[k] = der[j];
		k++;
		j++;
	}

}

void mergeSort(int ini, int fin)
{
	if(ini < fin)
	{
		int mid = (fin + ini) / 2;
		mergeSort(ini, mid);
		mergeSort(mid + 1, fin);
		merge(ini, mid, fin); 
	}
}


int main(void)
{
	int n, q, aux, res, counter = 1;
	while(cin >> n >> q && (n != 0 || q != 0))
	{
		canicas.clear();
		queries.clear();
		for(int i = 0 ; i < n ; i++)
		{
			cin >> aux;
			canicas.push_back(aux);
		}
		for(int i = 0 ; i < q ; i++)
		{
			cin >> aux;
			queries.push_back(aux);
		}
		
		mergeSort(0, canicas.size() - 1);
		/*
		for(auto a : canicas)
			cout << a << " ";
		cout <<"\n";
		for(auto a : queries)
			cout << a << " ";
		cout << "\n";
		*/
		
		cout << "CASE# " << counter << ":" <<"\n";
		for(auto a : queries)
		{
			res = itbinarySearch(a) + 1;
			if(res == 0)
				cout << a << " not found" << "\n";
			else
				cout << a << " found at " << res << "\n";
		}
		
		counter++;
	}

	return 0;
}