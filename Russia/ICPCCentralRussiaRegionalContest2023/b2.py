def buscaPraCimaX(pos, py):
    # retorna quantos marcados têm y < py na linha pos
    arr = mapx[pos]
    ini = 0
    fim = len(arr) - 1
    resp = 0

    while ini <= fim:
        meio = (ini + fim) // 2
        if arr[meio] < py:
            resp = meio + 1
            ini = meio + 1
        else:
            fim = meio - 1

    return resp


def buscaPraCimaY(pos, px):
    # retorna quantos marcados têm x < px na coluna pos
    arr = mapy[pos]
    ini = 0
    fim = len(arr) - 1
    resp = 0

    while ini <= fim:
        meio = (ini + fim) // 2
        if arr[meio] < px:
            resp = meio + 1
            ini = meio + 1
        else:
            fim = meio - 1

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

# ordenar
for r in mapx:
    mapx[r].sort()
for c in mapy:
    mapy[c].sort()

# caso sem célula livre
if n * m == k:
    print(0)
    print(0, 0)
    exit()

resp = 0
p1 = 0
p2 = 0

for px, py in marked:

    # direita
    if py + 1 <= m and (px, py + 1) not in marked:
        r1 = buscaPraCimaY(py + 1, px)  # acima
        r2 = buscaPraCimaX(px, py + 1)  # esquerda
        abaixo = len(mapy[py + 1]) - r1
        direita = len(mapx[px]) - r2

        for val in (r1, r2, abaixo, direita):
            if val > resp:
                resp = val
                p1 = px
                p2 = py + 1

    # esquerda
    if py - 1 >= 1 and (px, py - 1) not in marked:
        r1 = buscaPraCimaY(py - 1, px)
        r2 = buscaPraCimaX(px, py - 1)
        abaixo = len(mapy[py - 1]) - r1
        direita = len(mapx[px]) - r2

        for val in (r1, r2, abaixo, direita):
            if val > resp:
                resp = val
                p1 = px
                p2 = py - 1

    # baixo
    if px + 1 <= n and (px + 1, py) not in marked:
        r1 = buscaPraCimaY(py, px + 1)
        r2 = buscaPraCimaX(px + 1, py)
        abaixo = len(mapy[py]) - r1
        direita = len(mapx[px + 1]) - r2

        for val in (r1, r2, abaixo, direita):
            if val > resp:
                resp = val
                p1 = px + 1
                p2 = py

    if px - 1 >= 1 and (px - 1, py) not in marked:
        r1 = buscaPraCimaY(py, px - 1)
        r2 = buscaPraCimaX(px - 1, py)
        abaixo = len(mapy[py]) - r1
        direita = len(mapx[px - 1]) - r2

        for val in (r1, r2, abaixo, direita):
            if val > resp:
                resp = val
                p1 = px - 1
                p2 = py

print(resp)
print(p1, p2)

