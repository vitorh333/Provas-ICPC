import sys
input = sys.stdin.readline

def prodVetorial(x1, y1, x2, y2, x3, y3):
    return ((x1 - x2) * (y3 - y2)) - ((x3 - x2) * (y1 - y2))
    
    #Calcula o produto vetorial para saber a posicao relativa de p3 em relaçao a reta p1-p2
    #Se 0, p1, p2 e p3 são colineares
    #Se positivo p3 esta a direita da reta p1-p2
    #Se negativo p3 esta a esquerda da reta p1-p2


def convexHull(pontos):
    inferiores = []
    superiores = []

    #Comeca por inferiores

    pontos = sorted(set(pontos))

    for p in pontos:
        #print(pontos)
        while len(inferiores) >= 2 and prodVetorial(inferiores[-2][0], inferiores[-2][1], inferiores[-1][0], inferiores[-1][1], p[0], p[1]) < 0:
            inferiores.pop()

        inferiores.append(p)

    #Superiores
    pontos.reverse()
    for p in pontos:
        #print(pontos)
        while len(superiores) >= 2 and prodVetorial(superiores[-2][0], superiores[-2][1], superiores[-1][0], superiores[-1][1], p[0], p[1]) < 0:
            superiores.pop()

        superiores.append(p)

    
    #ESSA PRAGA NAO FUNCIONA PARA PONTOS COLINEARES

    #O primeiro cara do superiores é o ultimo do inferiores
    #O ultimo cara do inferiores é o primeiro dos superiores

    vis = set()
    hull = set()
    for p in inferiores + superiores:
        if p not in vis:
            vis.add(p)
            hull.add(p)
    
    return hull

n = int(input())
pontos = [-1] * (n)

for i in range(n):
    x, y = map(int, input().split())
    pontos[i] = (x, y)

v = convexHull(pontos)

cont = 1
for p in pontos:
    if p in v:
        sys.stdout.writelines(f"{cont} ")
    
    cont += 1
sys.stdout.writelines('\n')
