#include <iostream>
#include <vector>
#include <string>
using namespace std;

int carries(string arriba, string abajo)
{
    int prim, seg, suma = 0, res = 0;
    vector <int> siCarry(arriba.length(), 0);
    prim = arriba[arriba.length() - 1] - '0';
    seg = abajo[arriba.length() - 1] - '0';
    suma = prim + seg;
    if(suma >= 10)
    {
        siCarry[arriba.length() - 1] = 1;
        res = 1;
    }
    for(int i = arriba.length() - 2 ; i >= 0 ; i--)
    {
        prim = arriba[i] - '0';
        seg = abajo[i] - '0';
        suma = prim + seg;
        if(suma >= 10)
        {
            siCarry[i] = 1;
            res++;
        }
        else if(suma == 9 && siCarry[i + 1] == 1)
        {
            res++;
            siCarry[i] = 1;
        }
    }
    return res;
}

int main(void)
{
    string primer, segundo;
    int auxI, carry;
    string zero = "0";
    while(cin >> primer >> segundo && (primer != "0" || segundo != "0"))
    {
        if(primer.length() < segundo.length())
            while(primer.length() != segundo.length())
                primer.insert(0, zero);
        else if(primer.length() > segundo.length())
            while(primer.length() != segundo.length())
                segundo.insert(0, zero);
        carry = carries(primer, segundo);
        if(carry == 0)
            cout << "No carry operation.\n";
        else if(carry == 1)
            cout << "1 carry operation.\n";
        else
            cout << carry << " carry operations.\n";
    }

}
