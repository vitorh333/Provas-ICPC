import sys
sys.setrecursionlimit(10**6)


def dfs(v):
    if vivo[v]:
        return v

    for vizinho in grafo[v]:
        r = dfs(vizinho)
        if r != -1:
            return r

    return -1


N = 10**5
q = int(input())

grafo = [[] for _ in range(N+5)]
vivo = [True] * (N+5)

velhos = set()

chefe = 1
prox = 2

for i in range(q):
    t, x = map(int, input().split())

    if t == 1:
        grafo[x].append(prox)
        prox += 1

    else:
        vivo[x] = False

        if x in velhos:
            velhos.remove(x)

        if x != chefe:
            print(chefe)

        else:
            k = dfs(chefe)
            if k != -1:
                chefe = k
            else:
                chefe = 
