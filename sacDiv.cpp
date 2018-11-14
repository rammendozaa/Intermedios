#include <iostream>
#include <vector>
using namespace std;

void todosDiv(vector <int> &divisores)
{
    int lim = 2000000;
    divisores.resize(lim,0);
    for(int i = 1 ; i < lim ; ++i)
        for(int j = i ; j < lim ; j += i)
            divisores[j]++;

}


int main(void)
{
    vector <int> divisores;
    todosDiv(divisores);
    cout << "int divisores[5000000]= {";
    for(auto a : divisores)
        cout << ", " << a;
    cout << "};";
    return 0;
}
