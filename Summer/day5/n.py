import sys
sys.setrecursionlimit(10**6)

def ordena(l, r):
    if not pos[0]:
        return 0, 0
    
    if r-l == 1:
        return a[l], a[l]

    meio = (l+r)//2
    minL, maxL = ordena(l, meio)
    minR, maxR = ordena(meio, r)

    if max(maxL, maxR) - min(minL, minR) + 1!= r-l:
        pos[0] = False
        return 0, 0

    if minL > minR:
        resp[0] += 1
        return minR, maxL
    else:
        return minL, maxR

t = int(input())
for _ in range(t):
    resp = [0]
    pos = [True]
    n = int(input())
    a = list(map(int, input().split()))
    
    ordena(0, n)

    if pos[0]:
        print(resp[0])
    else:
        print(-1)
