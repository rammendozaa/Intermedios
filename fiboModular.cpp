#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct Matriz{
    long long int mat[2][2];
};

Matriz multMatriz(Matriz mat1, Matriz mat2, long long int modu)
{
    int i, j, k;
    Matriz matrizRes;
    for(i = 0 ; i < 2 ; i++)
        for(j = 0 ; j < 2 ; j++)
            for(matrizRes.mat[i][j] = k = 0 ; k < 2 ; k++)
                matrizRes.mat[i][j] += (mat1.mat[i][k] % modu) * (mat2.mat[k][j] % modu) ;
    return matrizRes;
}

Matriz fibo(Matriz base, long long int p, long long int modu)
{
    Matriz res;
    res.mat[0][1] = 1;
    res.mat[1][0] = 1;
    res.mat[0][0] = 1;
    res.mat[1][1] = 0;
    base = res;
    while(p)
    {
        if(p & 1)
            res = multMatriz(res, base, modu);
        base = multMatriz(base, base, modu);
        p >>= 1;
    }
    return res;
}


int main(void)
{
    long long int fiboN, expo;
    while(cin >> fiboN >> expo)
    {
        Matriz resultado;
        long long int fib, ex = pow(2, expo);
        resultado = fibo(resultado,fiboN - 1, ex);
        fib = resultado.mat[1][0];
        cout << fib % ex << "\n";
    }
    return 0;
}
