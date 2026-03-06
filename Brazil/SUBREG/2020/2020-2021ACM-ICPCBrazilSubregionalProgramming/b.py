mat = [[0 for i in range(10)] for i in range(10)]
 
n = int(input())
pode = True
for _ in range(n):
    d, l, px, py = map(int, input().split())
    if d == 0:
        tg = l-1 + py-1
 
        if tg >= 10:
            pode = False
        else:
            for i in range(l):
                mat[px-1][py-1+i] += 1
    else:
        tg = l-1 + px-1
 
        if tg >= 10:
            pode = False
 
        else:
            for i in range(l):
                mat[px-1+i][py-1] += 1
 
#print(mat)
for i in range(10):
    for j in range(10):
        if mat[i][j] > 1:
            pode = False
            break
    if not pode:
        break
 
if pode:
    print("Y")
else:
    print("N")
