n = int(input())
l = list(map(int, input().split()))
l.sort()

pode = False
for i in range(2, n):
    if l[i] < l[i-1] + l[i-2]:
        pode = True
        break

if pode:
    print("possible")
else:
    print("impossible")
