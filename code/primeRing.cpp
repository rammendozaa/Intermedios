#include <algorithm>
#include <vector>

using namespace std;

bool isPrime(long long int n)
{
    long long root = sqrt(n);
    for(int i = 0 ; i <= root ; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main(void)
{
    int cases, numb;
    cin >> cases;
    while(cases--)
    {
        cin >> numb;
        

    }
    return 0;
}
