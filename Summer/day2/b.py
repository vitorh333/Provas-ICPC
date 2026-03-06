import sys
from collections import deque

def bfs(inicio):
    fila = deque([inicio])
    vis[inicio] = True

    while fila:
        u = fila.popleft()
        for v in grafo[u]:
            if not vis[v]:
                vis[v] = True
                fila.append(v)


t = int(sys.stdin.readline())

for caso in range(t):

    # 🔹 pula linhas vazias antes de ler o maior vértice
    while True:
        linha = sys.stdin.readline()
        if linha.strip() != "":
            maior = linha.strip()
            break

    n = ord(maior) - ord('A') + 1

    grafo = [[] for _ in range(n)]
    vis = [False] * n

    # 🔹 leitura das arestas
    while True:
        linha = sys.stdin.readline()
        if not linha or linha.strip() == "":
            break

        u = ord(linha[0]) - ord('A')
        v = ord(linha[1]) - ord('A')

        grafo[u].append(v)
        grafo[v].append(u)

    comp = 0
    for i in range(n):
        if not vis[i]:
            bfs(i)
            comp += 1

    print(comp)
    if caso != t - 1:
        print()

