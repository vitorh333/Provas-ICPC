b, l = map(int, input().split())
dig = list(map(int, input().split()))

MOD = b + 1

s = 0
sinal = 1
for i in range(l - 1, -1, -1):
    s = (s + sinal * dig[i]) % MOD
    sinal *= -1

if s % MOD == 0:
    print(0, 0)
    exit()

for i in range(l):

    if (l - 1 - i) % 2 == 0:
        sign = 1
    else:
        sign = -1

    D = dig[i]

    r = (-s * sign) % MOD

    k = (r + D) // MOD
    delta = r - k * MOD

    if -D <= delta <= 0:
        x = D + delta
        print(i + 1, x)
        exit()

print(-1, -1)

