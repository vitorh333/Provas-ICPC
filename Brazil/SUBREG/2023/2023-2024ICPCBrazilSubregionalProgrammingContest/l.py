import sys

s = list(input().strip())
k = int(input())

n = len(s)
grupos = [[] for _ in range(k)]

for i in range(n):
    grupos[i % k].append(s[i])

for g in grupos:
    g.sort()

indices = [0] * k
res = []
for i in range(n):
    grupo = i % k
    res.append(grupos[grupo][indices[grupo]])
    indices[grupo] += 1

for i in range(n):
    sys.stdout.writelines(res[i])

print()
