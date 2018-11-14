#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double p, q, r, s, t, u;

double fun(double x)
{
	return (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u;
}

void binaria()
{
	double ini = 0, fin = 1, mid;
	while(fabs(fin - ini) >= 1e-7)
	{
		mid = (ini + fin) / 2;
		if(fun(mid) > 0)
			ini = mid;
		else
			fin = mid;
	}
	if(fabs(fun(mid) - 0) <= 1e-7)
		cout << fixed << setprecision(4) << mid << "\n";
	else
		cout << "No solution\n";
}

int main(void)
{
	while(cin >> p >> q >> r >> s >> t >> u)
		binaria();
	return 0;
}
