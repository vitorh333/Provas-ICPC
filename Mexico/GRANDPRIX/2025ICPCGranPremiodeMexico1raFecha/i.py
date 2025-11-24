from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(v, pai, grafo, hab):
    freq = defaultdict(int)

    for vizinho in grafo[v]:
        if vizinho == pai:
            continue
        
        freqVizinho = dfs(vizinho, v, grafo, hab)
        
        #print(freqVizinho)

        if len(freqVizinho) > len(freq):
            freq, freqVizinho = freqVizinho, freq

        for key in freqVizinho:
            freq[key] += freqVizinho[key]

    freq[hab[v]] += 1
    
    #print("freq", freq)
    
    for h, idx in querys[v]:
        resp[idx] = freq[h]

    return freq

n, q = map(int, input().split())
hab = list(map(int, input().split()))

grafo = defaultdict(list)

for i in range(n-1):
    v, u = map(int, input().split())
    v-=1
    u-=1
    grafo[v].append(u)
    grafo[u].append(v)

querys = [[] for i in range(n)]

for i in range(q):
    x, k = map(int, input().split())
    x -= 1
    querys[x].append((k, i))

resp = [-1] * q
dfs(0, -1, grafo, hab)
#print(resp)

for i in range(len(resp)):
    sys.stdout.writelines(f"{resp[i]}")
    sys.stdout.writelines('\n')
