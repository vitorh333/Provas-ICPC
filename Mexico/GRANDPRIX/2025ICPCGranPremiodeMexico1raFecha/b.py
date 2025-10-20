n = int(input())
l = list(map(int, input().split()))

maximo = l[0]
soma = l[0]
for i in range(1, n):
    #oq vale mais a pena, comecar daqui ou somar o proximo
    soma = max(l[i], soma + l[i])
    #maximo e o melhor entre minha decisao e o meu atual
    maximo = max(soma, maximo)
print(maximo)

