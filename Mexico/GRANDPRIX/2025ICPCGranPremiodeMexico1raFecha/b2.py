def epsiral(m, canto, sentido):
 
    linhas = len(m)
    colunas = len(m[0])
    res = []
    vis = [[False] * colunas for _ in range(linhas)]
 
    if canto == "se":
        x, y = 0, 0
    elif canto == "sd":
        x, y = 0, colunas - 1
    elif canto == "ie":
        x, y = linhas - 1, 0
    elif canto == "id":
        x, y = linhas - 1, colunas - 1
 
    if canto == "se":
        if sentido == "h":
            dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
        elif sentido == "ah":
            dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
    elif canto == "sd":
        if sentido == "h":
            dx, dy = [1, 0, -1, 0], [0, -1, 0, 1]
        elif sentido == "ah":
            dx, dy = [0, 1, 0, -1], [-1, 0, 1, 0]
    elif canto == "ie":
        if sentido == "h":
            dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]
        elif sentido == "ah":
            dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]
    
    elif canto == "id":
        if sentido == "h":
            dx, dy = [0, -1, 0, 1], [-1, 0, 1, 0]
        elif sentido == "ah":
            dx, dy = [-1, 0, 1, 0], [0, -1, 0, 1]
 
    dirIDX = 0
 
    for _ in range(linhas * colunas):
        res.append(m[x][y])
        vis[x][y] = True
 
        nx, ny = x + dx[dirIDX], y + dy[dirIDX]
 
        if not (0 <= nx < linhas and 0 <= ny < colunas and not vis[nx][ny]):
            dirIDX = (dirIDX + 1) % 4
            nx, ny = x + dx[dirIDX], y + dy[dirIDX]
        
        x, y = nx, ny
 
    return res
 
 
def kadane(l):
    maximo = l[0]
    soma = l[0]
    for i in range(1, len(l)):
        soma = max(l[i], soma + l[i])
        maximo = max(soma, maximo)
    return maximo
 
n = int(input())
m = []
resp = [0] * 8
 
for i in range(n):
    pk = list(map(int, input().split()))
    m.append(pk)
 
resp[0] = epsiral(m, "se", "h")
resp[1] = epsiral(m, "se", "ah")
resp[2] = epsiral(m, "sd", "h")
resp[3] = epsiral(m, "sd", "ah")
resp[4] = epsiral(m, "id", "h")
resp[5] = epsiral(m, "id", "ah")
resp[6] = epsiral(m, "ie", "h")
resp[7] = epsiral(m, "ie", "ah")
 
print(resp)
maior = 0
 
for i in range(8):
    maior = max(maior, kadane(resp[i]))
 
print(maior)
