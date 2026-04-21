import sys
from collections import defaultdict
sys.setrecursionlimit(10**6)
 
def dfs(v):
    for vizinho in grafoinv[v]:
        if not visitado[vizinho]:
            visitado[vizinho] = True
            
            pessoa = quem[vizinho]
            resp[0] = min(resp[0], idade[pessoa])
            
            dfs(vizinho)
 
 
n, m, p = map(int, input().split())
idade = list(map(int, input().split()))
 
grafoinv = defaultdict(list)
 
for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    grafoinv[y].append(x)
 
pos = list(range(n))
quem = list(range(n))
 
for _ in range(p):
    c = input().split()
    
    if c[0] == "P":
        e = int(c[1]) - 1
        
        inicio = pos[e]
        visitado = [False] * n
        visitado[inicio] = True
        
        resp = [10**18]
        
        dfs(inicio)
        
        if resp[0] == 10**18:
            print("*")
        else:
            print(resp[0])
    
    else:
        a = int(c[1]) - 1
        b = int(c[2]) - 1
        
        pa = pos[a]
        pb = pos[b]
        
        pos[a], pos[b] = pb, pa
        quem[pa], quem[pb] = quem[pb], quem[pa]
