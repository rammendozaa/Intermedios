import sys
import math

for line in sys.stdin:
    valores = []
    for var in line.split():
        valores.append(var)
    exp = int(valores[0])
    base = int(valores[1])
    if(exp == 0 and base == 0):
        exit()
    res = int(math.pow(base, exp))
    if(res % exp != base):
        print (f'yes')
    else:
        print (f'no')
