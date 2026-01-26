import sys
sys.setrecursionlimit(10**7)


def valid(i,  j):
    return 0 <= i < n and 0 <= j < k and not vis[i][j] and m[i][j] != 0

def dfs(i, j):
    vis[i][j] = True
    cnt[0] += m[i][j]

    if valid(i+1, j):
        dfs(i+1, j)

    if valid(i-1, j):
        dfs(i-1, j)

    if valid(i, j+1):
        dfs(i, j+1)

    if valid(i, j-1):
        dfs(i, j-1)



t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    m = []

    for i in range(n):
        pk = list(map(int, input().split()))
        m.append(pk)

    vis = [[False] * k for i in range(n)]
    
    maior = 0
    cnt = [0]
    for i in range(n):
        for j in range(k):
            if m[i][j] != 0 and not vis[i][j]:
                cnt[0] = 0
                dfs(i, j)
                maior = max(cnt[0], maior)

    print(maior)
