#Nao posso so rodar uma bfs para cada tempo e ve quando eu chego?

import sys
from collections import defaultdict

input = sys.stdin.readline

n, t = map(int, input().split())

grafos = [defaultdict(list) for _ in range(t + 1)]

for momento in range(1, t + 1):
    m = int(input())
    for _ in range(m):
        u, v = map(int, input().split())
        grafos[momento][u].append(v)
        grafos[momento][v].append(u)

k = int(input())
a = list(map(int, input().split()))

atual = set([1])

# 3 fors aqui ta dando um mal estar
# isso é n + soma das arestas mas as arestas <= 2*10e5

for i in range(k):
    momento = a[i]
    proximo = set(atual)

    for v in atual:
        for u in grafos[momento].get(v, []):
            proximo.add(u)

    atual = proximo

    if n in atual:
        print(i + 1)
        exit()

print(-1)

