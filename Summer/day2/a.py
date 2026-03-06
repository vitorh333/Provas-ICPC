n = int(input())
h = list(map(int, input().split()))
h.append(0)

melhor = 0
pilha = []

for i in range(n+1):
    ini = i
    while pilha and h[i] < pilha[-1][0]:
        hx, pos = pilha.pop()
        l = i-pos

        lado = min(hx,l)
        melhor = max(melhor, lado)
        ini = pos

    pilha.append((h[i], ini))

print(melhor)
