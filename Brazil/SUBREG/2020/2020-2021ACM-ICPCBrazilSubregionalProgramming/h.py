def comb(n, k):
    if k < 0 or k > n: return 0
    if k > n- k: k = n-k

    res = 1
    for i in range(1, k+1):
        res = res * (n-k+i) // i
    return res

n, k = map(int, input().split())
l = list(map(int, input().split()))
a, b = map(int, input().split())
l.sort()
l.reverse()

cap = b
qtd = k
resp = 0

for i in range(len(l)):
    if l[i] > cap:
        continue
    else:
        resp += comb(n-i-1, qtd)
        qtd-=1
        cap -= l[i]

        if qtd == 0:
            resp += 1
            break

cap = a-1
qtd = k
r = 0

for i in range(len(l)):
    if l[i] > cap:
        continue
    else:
        r += comb(n-i-1, qtd)
        qtd-=1
        cap-=l[i]

        if qtd == 0:
            r += 1
            break

print(resp-r)
