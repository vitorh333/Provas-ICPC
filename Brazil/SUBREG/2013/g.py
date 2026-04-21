n, m = map(int, input().split())
mat = []
for i in range(n):
    pk = list(map(int, input().split()))
    mat.append(pk)
 
cont = 1
target = [[-1 for i in range(m)] for i in range(n)]
 
for i in range(n):
    for j in range(m):
        target[i][j] = cont
        cont += 1
 
 
pos = [-1] * n
for i in range(n):
    aux1 = set(mat[i])
    tem = False
    for j in range(n):
        aux2 = set(target[j])
        if aux1 == aux2:
            tem = True
            pos[i] = j
 
    if not tem:
        print("*")
        exit()
 
 
visitado = [False] * n
c1 = 0
 
for i in range(n):
    if not visitado[i]:
        ciclo = 0
        j = i
        while not visitado[j]:
            visitado[j] = True
            j = pos[j]
            ciclo += 1
        
        if ciclo > 1:
            c1 += ciclo - 1
 
nova = [None] * n
for i in range(n):
    nova[pos[i]] = mat[i]
 
mat = nova
 
pos2 = [-1] * m
for j in range(m):
    col = [mat[i][j] for i in range(n)]
    achou = False
 
    for k in range(m):
        t = [target[i][k] for i in range(n)]
 
        if col == t:
            pos2[j] = k
            achou = True
            break
 
    if not achou:
        print("*")
        exit()
 
visitado = [False] * m
c2 = 0
 
for i in range(m):
    if not visitado[i]:
        ciclo = 0
        j = i
        
        while not visitado[j]:
            visitado[j] = True
            j = pos2[j]
            ciclo += 1
        
        if ciclo > 1:
            c2 += ciclo - 1
 
print(c1 + c2)
