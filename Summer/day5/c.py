n = int(input())
best = -1
for _ in range(n):
    x, y = map(int, input().split())
    maior = max(x, y)
    best = max(maior, best)

if best % 2 == 0:
    print("N")
else:
    print("Y")
