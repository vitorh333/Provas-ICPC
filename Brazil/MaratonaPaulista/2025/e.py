from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)

def dfs(v):
    vis.add(v)
    cont[0] += v

    for vizinho in grafo[v]:
        if vizinho not in vis:
            dfs(vizinho)


n, k = map(int, input().split())
aux = []

for i in range(n):
    d, p = map(int, input().split())
    aux.append((d, p))

aux.sort()

grafo = defaultdict(list)

for d, p in aux:
    grafo[p] = []

for i in range(len(aux) - 1):
    d1, p1 = aux[i]
    d2, p2 = aux[i+1]

    if abs(d2 - d1) <= k:
        grafo[p1].append(p2)
        grafo[p2].append(p1)


vis = set()
resp = []

for v in grafo:
    if v not in vis:
        cont = [0]
        dfs(v)
        resp.append(cont[0])

resp.sort()
if len(resp) == 1:
    print(resp[-1])
else:
    print(resp[-1] + resp[-2])
