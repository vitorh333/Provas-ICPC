def dfs(grafo, hab, v):
    total = 1
    for viznho in grafo[v]:
        total += dfs(grafo, hab, viznho)
    resp[(v, hab[v])] = total
    return total


from collections import defaultdict
import sys
sys.setrecursionlimit(10**7)

n, q = map(int, input().split())
hab = list(map(int, input().split()))

grafo = defaultdict(list)

for i in range(n-1):
    v, u = map(int, input().split())
    v-=1
    u-=1
    grafo[v].append(u)

resp = defaultdict(int)
dfs(grafo, hab, 0)

print(resp)
