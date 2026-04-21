from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)


def dfs(v, pai, l):
    level[v] = l
    
    ruim = (s[v] > k)

    for vizinho in g[v]:
        if vizinho != pai:
            dfs(vizinho, v, l+1)
            
            if f[vizinho] > 0 or s[vizinho] > k:
                f[v] += f[vizinho] + 1
                ruim = True

    if s[v] > k:
        ruim = True

    if ruim and f[v] == 0:
        f[v] = 0
        

n, k = map(int, input().split())
s = list(map(int, input().split()))

g = defaultdict(list)

for i in range(n-1):
    v, u = map(int, input().split())
    v-= 1
    u -= 1
    g[v].append(u)
    g[u].append(v)

f = [0] * n
level = [0] * n
dfs(0, -1, 0)

resp = 2 * f[0]

desc = -1
for v in range(n):
    if s[v] > k:
        desc = max(desc, level[v])

if desc == -1:
    print(0)
else:
    print(resp - desc)
