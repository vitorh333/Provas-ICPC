def aresta(px, py, x1, y1, x2, y2):
    
    if (px - x1) * (y2 - y1) != (py - y1) * (x2 - x1):
        return False
    
    if min(x1, x2) <= px <= max(x1, x2) and min(y1, y2) <= py <= max(y1, y2):
        return True
    
    return False

def dentro(ponto, poligono):
    x, y = ponto
    dentro = False
    n = len(poligono)
    
    for i in range(n):
        x1, y1 = poligono[i]
        x2, y2 = poligono[(i + 1) % n]
        
        if(aresta(x, y, x1, y1, x2, y2)): return True

        if ((y1 > y) != (y2 > y)):
            intersecao = x1 + (y - y1) * (x2 - x1) / (y2 - y1)
            
            if x < intersecao:
                dentro = not dentro
    
    return dentro


poligono = [(0, 100), (100, 0), (200, 0), (100, -100), (0, -100), (-100, 0), (-200, 0), (-100, 100)]

n = int(input())
for _ in range(n):
    x, y = map(int, input().split())

    if((x, y) in poligono): print("S")
    elif dentro((x, y), poligono): print("S")
    else: print("N")
