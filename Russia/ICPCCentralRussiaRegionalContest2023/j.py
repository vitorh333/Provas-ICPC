import sys
from collections import defaultdict
input = sys.stdin.readline

n, m = map(int, input().split())
matriz = [list(input().strip()) for _ in range(n)]
s = input()

DR = [[-1]*m for _ in range(n)]
DL = [[-1]*m for _ in range(n)]
DD = [[-1]*m for _ in range(n)]
DU = [[-1]*m for _ in range(n)]

for i in range(n):
    ultimo = -1
    for j in range(m-1, -1, -1):
        if matriz[i][j] == "#":
            ultimo = -1
        else:
            if ultimo == -1:
                ultimo = (i, j)
            DR[i][j] = ultimo

for i in range(n):
    ultimo = -1
    for j in range(m):
        if matriz[i][j] == "#":
            ultimo = -1
        else:
            if ultimo == -1:
                ultimo = (i, j)
            DL[i][j] = ultimo


for j in range(m):
    ultimo = -1
    for i in range(n-1, -1, -1):
        if matriz[i][j] == "#":
            ultimo = -1
        else:
            if ultimo == -1:
                ultimo = (i, j)
            DD[i][j] = ultimo

for j in range(m):
    ultimo = -1
    for i in range(n):
        if matriz[i][j] == "#":
            ultimo = -1
        else:
            if ultimo == -1:
                ultimo = (i, j)
            DU[i][j] = ultimo

x, y = 1, 1
i, j = n - x, y - 1

for c in s:
    if c == "R":
        i, j = DR[i][j]
    elif c == "L":
        i, j = DL[i][j]
    elif c == "U":
        i, j = DU[i][j]
    elif c == "D":
        i, j = DD[i][j]

xfinal = n - i
yfinal = j + 1

print(yfinal, xfinal)

