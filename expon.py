import sys
import math
import decimal
from decimal import Decimal
def potencia(acu,num, mul):
    if mul == 1:
        return acu * num
    else:
        return potencia(num * acu,num,mul - 1)

for line in sys.stdin:
    valores = []
    for var in line.split():
        valores.append(var)
    base = valores[0]
    exp = valores[1]
    mult = 1
    res1 = potencia(1, 95.123, 12)
#    res = str(Decimal(potencia(1, base, exp)))
#    print (res.rstrip('0').rstrip('.'))
#    print("%g" % (Decimal(math.pow(base, 7))))
#    print (f'{math.pow(base, 7):g}')

    print("{:.100f}".format(res1))
    print(f'{pow(Decimal(float(base)),Decimal(int(exp)))}')
    print("{:.100f}".format(math.pow(float(95.123),12)))
    print("{:.100f}".format(pow(95.123,12)))
    print(f'{base} \t {exp}')
#    95.123 12
