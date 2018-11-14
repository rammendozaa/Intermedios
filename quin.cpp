import sys

def fact(fa, i):
    if fa == 0:
        return i
    else:
        return fact(fa - 1, i * fa)


for line in sys.stdin:
    n = int(line)
    res = fact(n, 1)
    print (f'{n}!\n{res}')
