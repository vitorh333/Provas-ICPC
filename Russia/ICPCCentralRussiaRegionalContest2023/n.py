n = int(input())
a = list(input().split())


ini = 0
fim = 10**18
resp = -1

while fim >= ini:
    maior = False
    menor = False
    meio = (ini + fim) // 2

    
    for i in range(n):
        if a[i] != "?":
            p = meio / (i + 1)
            p = int(p + 0.5)

            if p > int(a[i]):
                maior = True
                break
            elif p < int(a[i]):
                menor = True
                break

    if maior:
        fim = meio -1

    elif menor:
        ini = meio + 1

    else:
        resp = meio
        fim = meio - 1

print(resp)

