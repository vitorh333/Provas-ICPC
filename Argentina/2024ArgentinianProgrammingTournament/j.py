from collections import deque

def testa():
    pode = False
    resp = []
    ind = -1
    for i in range(len(v)-1):
        if v[i] + v[i+1] == x:
            ind = i

    if ind != -1:
        if v[0] + v[ind] != x and v[0] + v[ind + 1] != x:
            for i in range(1, ind+1):
                resp.append(v[i])
            resp.append(v[0])

            for i in range(ind+1, n):
                resp.append(v[i])

            pode = True

        elif v[n-1] + v[ind] != x and v[n-1] + v[ind + 1] != x:
            for i in range(ind+1):
                resp.append(v[i])
            resp.append(v[n-1])

            for i in range(ind+1,n-1):
                resp.append(v[i])

            pode = True

        if pode:
            print(*resp)
        else:
            print("*")

    else:
        print(*v)


n, x = map(int, input().split())
v = list(map(int, input().split()))
v.sort()

e = []
d = []
m = []

if x % 2 == 0:
    pode = True
    meio = x // 2

    for k in v:
        if k > meio: d.append(k)
        elif k < meio: e.append(k)
        else: m.append(k)

    
    if len(m) > 0:
        res = deque()

        if len(m) > 0:
            res.appendleft(m[-1])
            m.pop()

        for i in range(len(e)):
            res.appendleft(e[i])

            if len(m) > 0:
                res.appendleft(m[-1])
                m.pop()

        for i in range(len(d)):
            res.append(d[i])

            if len(m) > 0:
                res.append(m[-1])
                m.pop()

        if len(m) > 0:
            pode = False

        if pode:
            print(*res)
        else:
            print("*")
    else:
        testa()
else:
    testa()
