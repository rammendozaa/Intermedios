def fact(fa, i):
    if fa == 0:
        return i
    else:
        return fact(fa - 1, i * fa)

cases = int(raw_input())
while cases > 0:
    n = int(raw_input())
    res = fact(n, 1)
    print res
    cases -= 1
