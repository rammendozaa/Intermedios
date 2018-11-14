import sys
import math

casos = 0
for line in sys.stdin:
    valores = []
    for var in line.split():
        valores.append(var)
    cuenta = int(valores[0])
    personas = int(valores[1])
    if(personas == 0 and cuenta == 0):
        exit()
    suma = 0
    while cuenta > 0:
        dinero = int(input())
        suma += dinero
        cuenta -= 1
    casos += 1
    res = suma//personas
    print(f'Bill #{casos} costs {suma}: each friend should pay {int(res)}\n')
