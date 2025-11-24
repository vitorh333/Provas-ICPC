n = int(input())

INF = 10**18

xmax = -INF
ymax = -INF
xmin = INF
ymin = INF

for i in range(n):
    x, y = map(int, input().split())
    xmax = max(xmax, x)
    xmin = min(xmin, x)
    ymax = max(ymax, y)
    ymin = min(ymin, y)


print(((xmax - xmin) + (ymax - ymin) + 4) * 2)
