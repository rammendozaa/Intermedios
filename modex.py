import sys
import math
def expoBin(a, b, m):
    if (b == 1):
        return a % m
    if(b % a == 0):
        n = (expoBin(a, b/2, m)) % m
        return (n * n) % m
    else:
        n = (expoBin(a, b-1, m)) % m
        return (n * (a % m)) % m

cases = int(input())
#while cases > 0:
for line in sys.stdin:
    valores = []
    for var in line.split():
        valores.append(var)
    x = int(valores[0])
    y = int(valores[1])
    n = int(valores[2])
    z = int(math.pow(2,2147483647) % 13)
    #z = expoBin(x, y, n)
    print (f'{x} {y} {n} {z}')
    cases -= 1
igno = int(input())
