n = int(input())

if n >= 3 or n == 1:
    print("S")

else:
    aux = []
    pode = False
    for i in range(n):
        pk = list(map(int, input().split()))
        aux.append(pk)


    v1 = []
    v2 = []
    tt = []

    for i in range(1, len(aux[0])):
        v1.append(aux[0][i])
        tt.append(aux[0][i])
    for i in range(len(aux[1]) -1, 0, -1):
        v2.append(aux[1][i])
        tt.append(aux[1][i])


    v3 = v1 + v2
    tt.sort()
    if v3 == tt:
        pode = True
    if pode:
        print("S")
    else:
        print("N")

