n, m = map(int, input().split())
sx = [True] * (n)

for i in range(m):
    r = list(input())

    if r[0] == "-":
        sx[int(r[1])] = False
    else:
        sx[int(r[1])] = True



