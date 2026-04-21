def aresta(px, py, x1, y1, x2, y2):

    if (px - x1) * (y2 - y1) != (py - y1) * (x2 - x1):
        return False

    if min(x1, x2) <= px <= max(x1, x2) and min(y1, y2) <= py <= max(y1, y2):
        return True

    return False


# confere se um ponto esta dentro de um poligono
def dentro(ponto, poligono):
    x, y = ponto
    dentro = False
    n = len(poligono)

    for i in range(n):
        x1, y1 = poligono[i]
        x2, y2 = poligono[(i + 1) % n]
        
        # Se o ponto estiver sobre um vertice ou aresta
        if(aresta(x, y, x1, y1, x2, y2)): return True

        if ((y1 > y) != (y2 > y)):
            intersecao = x1 + (y - y1) * (x2 - x1) / (y2 - y1)

            if x < intersecao:
                dentro = not dentro

    return dentro
