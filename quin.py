import sys
def fact(fa):
    if fa == 4:
        return 24
    else:
        return fa * fact(fa - 1)

for line in sys.stdin:
    n = int(line)
    if n == 0:
        print (f'0!\n1')
    elif n == 1:
        print (f'1!\n1')
    elif n == 2:
        print (f'2!\n2')
    elif n == 3:
        print (f'3!\n6')
    else:
        res = fact(n)
        print (f'{n}!\n{res}')
