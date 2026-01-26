# GUERRAAAAAAAAAAAAAAAAAAAAAAAA
import math

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    i = input()
    f = input()

    d = (10**(a + b)) - 10**a
    n = int(i+f) - int(i)

    #print(n, d)

    k = math.gcd(n, d)

    if k != 1:
        d = d // k
        n = n // k

    print(n, d)
