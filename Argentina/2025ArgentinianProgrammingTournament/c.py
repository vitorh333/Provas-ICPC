n = int(input())
P = list(map(int, input().split()))

P = [x - 1 for x in P]

posVal = [0] * n
for i, val in enumerate(P):
    posVal[val] = i

freqA = [0] * n
freqB = [0] * n

for x in range(n):
    v = (posVal[x] + x) % n
    freqA[v] += 1

for y in range(n):
    v = (P[y] + y) % n
    freqB[v] += 1

total = 0
for v in range(n):
    total += freqA[v] * freqB[v]

print(total)


