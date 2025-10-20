import math

def calcDist(xa, ya, xb, yb):
    return math.sqrt((xa - xb) ** 2 + (ya - yb) ** 2)

def dot(xa, ya, xb, yb):
    return xa * xb + ya * yb

eps = 1e-9

pontos = []

for i in range(4):
    x, y = map(int, input().split())
    pontos.append((x, y))

lados = []
for i in range(4):
    x1, y1 = pontos[i]
    x2, y2 = pontos[(i + 1) % 4]
    lados.append(calcDist(x1, y1, x2, y2))

pode = True
for i in range(1, 4):
    if abs(lados[i] - lados[0]) > eps:
        pode = False
        break

if pode:
    for i in range(4):
        p1 = pontos[i]
        p2 = pontos[(i + 1) % 4]
        p3 = pontos[(i + 2) % 4]

        v1x, v1y = p1[0] - p2[0], p1[1] - p2[1]
        v2x, v2y = p3[0] - p2[0], p3[1] - p2[1]

        if abs(dot(v1x, v1y, v2x, v2y)) > eps:
            pode = False
            break

if pode:
    print("SIM")
else:
    print("NAO")

