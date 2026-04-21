def mask(n, bad):
    cont = 0

    for i in range(1 << n):
        cp = 0
        cs = 0

        testa = []
        for j in range(n):
            if (i & (1 << j)) != 0:
                if j < p:
                    cp += 1
                elif j < p + s:
                    cs += 1

        if cp != 1 or cs != 1:
            continue

        ok = True

        for k in range(n):
            if i & (1 << k):
                if bad[k] & i:
                    ok = False
                    break

        if ok:
            cont += 1

    return cont


n, r, p, s,= map(int, input().split())
bad = [0] * n

for i in range(r):
    v, u = map(int, input().split())
    v-= 1;
    u-= 1;
    bad[v] |= (1 << u)
    bad[u] |= (1 << v)


#print(pp, ss)
resp = mask(n, bad)
print(resp)
