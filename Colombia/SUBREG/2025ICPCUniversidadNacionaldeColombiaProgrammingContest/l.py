t = int(input())

for _ in range(t):
    m = int(input())
    resp = 1
    anterior = 1

    

    for i in range(m):
        if i % 2 == 0:
            resp += anterior
        else:
            resp += anterior * 2
            anterior = anterior * 2
    

    print(resp)


