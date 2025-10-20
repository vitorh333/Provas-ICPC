from itertools import combinations

K = int(input())

matriz = [str(i) for i in range(1,10)]

posicoes = list(range(9))
Menorlucro = 10**18
melhor = []

for curinga in combinations(posicoes, K):
    temp = matriz.copy()
    for p in curinga:
        temp[p] = '*'
    
    lucro = 0
    linhas = [
        [0,1,2],[3,4,5],[6,7,8],   
        [0,4,8],[2,4,6]            
    ]
    
    for l in linhas:
        valores = [temp[i] for i in l if temp[i] != '*']
        if valores and all(v == valores[0] for v in valores):
            lucro += 1
    
    if lucro < Menorlucro:
        Menorlucro = lucro
        melhor = temp

for i in range(3):
    print(''.join(melhor[3*i:3*i+3]))

