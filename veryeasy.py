import sys
import math

for line in sys.stdin:
    valores = []
    for var in line.split():
        valores.append(var)
    N = int(valores[0])
    A = int(valores[1])
    i = 1
    suma = 0
    while i < N:
        suma += (i * math.pow(A,i))
        i += 1
    print(f'{int(suma)}')
