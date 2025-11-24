from collections import defaultdict
import sys
sys.setrecursionlimit(10**6 + 10)


def dfs(v, grafo, vis, matching):
    for vizinho in grafo[v]:
        if not vis[vizinho]:
            vis[vizinho] = True

            if matching[vizinho] == -1 or dfs(matching[vizinho], grafo, vis, matching):
                matching[vizinho] = v
                return True

    return False


direcoes = [
        
        (-2, 1), (-2, -1),
        (-1, 2), (-1, -2),
        (1, 2), (1, -2),
        (2, -1), (2, 1)
        
        ]


n, k = map(int, input().split())
tab = [[ False for _ in range(n)] for _ in range(n)]
mapeamento = defaultdict(int)

for i in range(k):
    l, c = map(int, input().split())
    l -= 1
    c -= 1
    tab[l][c] = True
    mapeamento[(l, c)] = i

grafo = [[] for _ in range(k)]
brancas = []
pretas = []

for key in mapeamento:
    l, c = key


    if(l + c) % 2 == 0:
        brancas.append(mapeamento[key])

    else:
        pretas.append(mapeamento[key])


    for dx, dy in direcoes:
        px, py = l + dx, c + dy
    

        if 0 <= px < n and 0 <= py < n and tab[px][py]:
            v = mapeamento[(px, py)]            
            grafo[mapeamento[key]].append(v)


matching = [-1] * k
emparelhamentos = 0


for i in range(len(brancas)):
    vis = [False] * k

    if dfs(brancas[i], grafo, vis, matching):
        emparelhamentos += 1
    

#print(matching)
print(emparelhamentos)

