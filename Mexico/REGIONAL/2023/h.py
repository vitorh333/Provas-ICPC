
import sys
import math
sys.setrecursionlimit(10 ** 6)


def encontraPontes(n, grafo):
    tempo = [-1] * n
    low = [-1] * n
    vis = [False] * n
    pontes = []
    t = 0

    def dfs(v, pai):
        nonlocal t
        vis[v] = True
        tempo[v] = low[v] = t
        t += 1

        for viz in grafo[v]:
            if viz == pai:
                continue
            if vis[viz]:
                low[v] = min(low[v], tempo[viz])
            else:
                dfs(viz, v)
                low[v] = min(low[v], low[viz])
                if low[viz] > tempo[v]:
                    pontes.append((v, viz))

    for i in range(n):
        if not vis[i]:
            dfs(i, -1)

    return pontes


def contaFolhas(v, pai, superGrafo, cont, visitados):
    visitados[v] = True
    grau = 0
    for viz in superGrafo[v]:
        if viz != -1:
            grau += 1

    if superGrafo[v][0] != -1 and grau == 1:
        cont[0] += 1
    
    for viz in superGrafo[v]:
        if viz != pai and viz != -1 and not visitados[viz]:
            contaFolhas(viz, v, superGrafo, cont, visitados)
    return cont

n, m = map(int, input().split())
grafo = [[] for i in range(n)]

for i in range(m):
    v, u = map(int, input().split())
    v -= 1
    u -= 1
    grafo[v].append(u)
    grafo[u].append(v)


superGrafo = [[] for _ in range(n)]
pontes = encontraPontes(n, grafo)
#print("Pontes:", pontes)

if len(pontes) == 0:
    print(0)
    exit()

visitadosupergrafo = [False] * n
for u, v in pontes:
    superGrafo[u].append(v)
    superGrafo[v].append(u)
    visitadosupergrafo[u] = True
    visitadosupergrafo[v] = True

for i in range(n):
    if not visitadosupergrafo[i]:
        superGrafo[i].append(-1)

visitados = [False] * n
resp = 0
isolados = 0

for i in range(n):
    if not visitados[i]:
        if superGrafo[i][0] == -1:
            isolados += 1
            visitados[i] = True
        else:
            cont = [0]
            stack = [(i, -1)]
            while stack:
                v, pai = stack.pop()
                visitados[v] = True
                grau = sum(1 for u in superGrafo[v] if u != -1)
                if grau == 1:
                    cont[0] += 1
                for u in superGrafo[v]:
                    if u != pai and u != -1 and not visitados[u]:
                        stack.append((u, v))
            resp += cont[0]

total= resp + 2 * isolados
arestas = math.ceil(total / 2)

print(arestas)
