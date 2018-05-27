from decimal import Decimal, getcontext
tcase = int(input())
getcontext().prec = 1100
for _ in range(tcase):
    n = int(input())
    g = int(Decimal(n).sqrt())
    print(g & 1)