import sys
input = sys.stdin.readline

n = int(input().strip())
matriz = []

for i in range(n):
    pk = list(map(int, input().split()))
    matriz.append(pk)

for k in range(n):
    for i in range(n):
        for j in range(n):
            if matriz[i][j] > matriz[i][k] + matriz[k][j]:
                print(-1)
                exit()

r = 0
for i in range(n):
    for j in range(i + 1, n):
        sentido = False
        for k in range(n):
            if k == i or k == j:
                continue
            if matriz[i][j] == matriz[i][k] + matriz[k][j]:
                sentido = True
                break
        if sentido:
            r += 1

print(r)

