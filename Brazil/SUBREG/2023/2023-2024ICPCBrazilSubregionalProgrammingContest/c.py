import sys
sys.setrecursionlimit(10**6 + 10)

def buscaPos(target):
    ini = 0
    fim = len(lis) - 1
    resp = len(lis)

    while fim >= ini:
        meio = (ini + fim) // 2

        if lis[meio] >= target:
            resp = meio
            fim = meio -1

        else:
            ini = meio + 1

    return resp

def dfs(v, pai, grafo, resp):
    pos = buscaPos(f[v])

    if pos == len(lis):
        lis.append(f[v])
        usado = True

    else:
        remontado = lis[pos]
        lis[pos] = f[v]
        usado = False
    
    #print(lis)
    resp[v] = len(lis)

    for vizinho in grafo[v]:
        if vizinho != pai:
            dfs(vizinho, v, grafo, resp)

    if usado:
        lis.pop()
    else:
        lis[pos] = remontado

n = int(input())
lig = list(map(int, input().split()))

grafo = [[] for i in range(n)]

for v in range(n-1):
    grafo[v + 1].append(lig[v]-1)
    grafo[lig[v]-1].append(v+1)

f = list(map(int, input().split()))
resp = [-1] * n
lis = []
dfs(0, -1, grafo, resp)

for i in range(1, len(resp)):
    sys.stdout.writelines(f"{resp[i]} ")
sys.stdout.writelines('\n')

