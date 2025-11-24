def buscaPraCimaX(pos, py):
    ini = 0
    fim = len(mapx[pos]) - 1
    resp = 0

    while fim >= ini:
        meio = (ini + fim) // 2

        if mapx[pos][meio] > py:
            resp = meio
            fim = meio - 1
        else:
            ini = meio + 1

    return resp

def buscaPraCimaY(pos, px):
    ini = 0
    fim = len(mapy[pos]) - 1
    resp = 0

    while fim >= ini:
        meio = (ini + fim) // 2

        if mapy[pos][meio] > px:
            resp = meio
            fim = meio - 1
        else:
            ini = meio + 1

    return resp


from collections import defaultdict

n, m, k = map(int, input().split())

mapx = defaultdict(list)
mapy = defaultdict(list)
marked = set()

for _ in range(k):
    x, y = map(int, input().split())
    mapx[x].append(y)
    mapy[y].append(x)
    marked.add((x, y))

for r in mapx:
    mapx[r].sort()
for c in mapy:
    mapy[c].sort()

if n * m == k:
    print(0)
    print(0, 0)
else:
    resp = 0
    p1 = 0
    p2 = 0
    

    for px, py in marked:    
        if (px, py + 1) not in marked and py + 1 <= m:
            r1 = buscaPraCimaY(py+1, px)
            r2 = buscaPraCimaX(px, py+1)

            if r1 > resp:
                resp = r1
                p1 = px
                p2 = py+1

            if r2 > resp:
                resp = r2
                p1 = px
                p2 = py+1

            if len(mapy[py+1]) - r1 > resp:
                resp = len(mapy[py+1]) - r1
                p1 = px
                p2 = py + 1

            if len(mapx[px]) - r2 > resp:
                resp = len(mapx[px]) - r2
                p1 = px
                p2 = py + 1

        if(px, py - 1) not in marked and py >= 1:
            r1 = buscaPraCimaY(py-1, px)
            r2 = buscaPraCimaX(px, py-1)

            if r1 > resp:
                resp = r1
                p1 = px
                p2 = py-1

            if r2 > resp:
                resp = r2
                p1 = px
                p2 = py-1

            if len(mapy[py-1]) - r1 > resp:
                resp = len(mapy[py-1]) - r1
                p1 = px
                p2 = py - 1

            if len(mapx[px]) - r2 > resp:
                resp = len(mapx[px]) - r2
                p1 = px
                p2 = py - 1
 
        if (px + 1, py) not in marked and px + 1 <= n:
            r1 = buscaPraCimaY(py, px+1)
            r2 = buscaPraCimaX(px+1, py)


            if r1 > resp:
                resp = r1
                p1 = px + 1
                p2 = py

            if r2 > resp:
                resp = r2
                p1 = px + 1
                p2 = py

            if len(mapy[py]) - r1 > resp:
                resp = len(mapy[py]) - r1
                p1 = px + 1
                p2 = py

            if len(mapx[px+1]) - r2 > resp:
                resp = len(mapx[px+1]) - r2
                p1 = px + 1
                p2 = py
 
        if (px - 1, py) not in marked and px -1 >= 1:
            r1 = buscaPraCimaY(py, px -1)
            r2 = buscaPraCimaX(px-1, py)

            if r1 > resp:
                resp = r1
                p1 = px - 1
                p2 = py

            if r2 > resp:
                resp = r2
                p1 = px - 1
                p2 = py

            if len(mapy[py]) - r1 > resp:
                resp = len(mapy[py]) - r1
                p1 = px-1
                p2 = py

            if len(mapx[px-1]) - r2 > resp:
                resp = len(mapx[px-1]) - r2
                p1 = px-1
                p2 = py

    print(resp)
    print(p1, p2)
