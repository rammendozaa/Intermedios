#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myOrden(long long int i , long long int j)
{
    return (j < i);
}

int main(void)
{
    long long int s, auxI, sum;
    cin >> s;
    vector <int> A(s);
    vector <int> B(s);
    for(int i = 0 ; i < s ; i++)
    {
        cin >> auxI;
        A[i] = auxI;
    }
    for(int i = 0 ; i < s ; i++)
    {
        cin >> auxI;
        B[i] = auxI;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), myOrden);
    sum = 0;
    for(int i = 0 ; i < s ; i++)
        sum += A[i] * B[i];
    cout << sum << "\n";
}
