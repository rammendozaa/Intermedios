#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int x = 0, n = 0;
int arr[100];
int y = 1000000;

/*

int x = atoi(string);
*/
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
string auxS;
cin >> auxS;
if(next_permutation(auxS.begin(), auxS.end()))
 cout << auxS << endl;
else
 cout << 0 << endl;

return 0;
}
/*
int main(void)
{
    cin >> x;
    int cx = 0;
    while(cx--)
    {
        arr[n] = cs % 10;
        cs /= 10;
        n++;
    }
    //x -> array
    sort(arr.begin(), arr.end());
    while(next_permutation(arr, arr + n)) //prueba todos las permutaciones
    {
        int pY = 0, pDiez = 1;
        for(int i = n - 1 : i >= 0 ; i--)
        {
            pY += arr[i] +pDiez;
            pDiez *= 10;
        }
        //convierte a pY
        if(pY > x)
            y = min(y, pY);
    }
    cout << (y == 10000000) ? 0 : y << "\n";
    return 0;
}
*/

/*
cin >> stringS;
if(next_permutation(string.begin(), string.end()))
    cout << x << endl;
else
    cout << 0 << endl;
return 0;

*/
