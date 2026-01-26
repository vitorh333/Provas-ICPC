def tentaA(i, j):
    if valid(i, j) and valid(i, j+1) and valid(a, j+2) and valid(i+1, j+1) and valid(i+2, j+1) and valid(i+3, j+1) and valid(i+4, j+1)

def valid(i, j):
    return 0 <= i < n and 0 <= j < m and not vis[i][j]

n, m = map(int, input().split())
mat = []

for i in range(n):
    pk = input()
    mat.append(pk)

vis = [[False for _ in range(m)] for _ in range(n)]
r = []

for i in range(n):
    for j in range(m):
        if mat[i][j] == "#" and not vis[i][j]:
            if tentaA(i, j):
                ok = True
                a += 1

            elif tentaP(i, j):
                ok = True
                p+=1

            elif tentaT(i, j):
                ok = True

            if not ok:
                print("Ue")


for e in r:
    if e == A:
        a += 1
    elif e == T:
        t += 1
    elif e == P:
        p += 1

