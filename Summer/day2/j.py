n = int(input())
l = list(map(int, input().split()))
tem = False

for i in range(n):
    a = l[i]
    b = l[a-1]
    c = l[b-1]

    if c == i + 1:
        tem = True

if tem:
    print("Yes")
else:
    print("No")
