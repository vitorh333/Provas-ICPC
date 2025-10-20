def maiorpool(v):
    maxarea = 0
    pilha = []

    for i in range(n):
        while pilha and v[i] >= v[pilha[-1]]:
            
            #print("aqui: ")
            #print(pilha)

            meio = pilha.pop()
            if not pilha:
                break
            l = pilha[-1]
            r = i
            altura = min(v[l], v[r])
            area = 0
            
            for j in range(l+1, r):
                area += max(0, altura - v[j])
            
            maxarea = max(maxarea, area)
            
            #print(f"area: {maxarea}")

        pilha.append(i)
        #print("pilha: ")
        #print(pilha)
    
    return maxarea

n = int(input())
v = list(map(int, input().split()))
print(maiorpool(v))

