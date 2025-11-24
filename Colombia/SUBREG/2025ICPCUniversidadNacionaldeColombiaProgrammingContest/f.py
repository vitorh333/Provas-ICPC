VALORMAXIMO = 2 * 10**7 + 10
menorFatorPrimo = [i for i in range(VALORMAXIMO)]

def crivo():
    i = 2
    while i * i < VALORMAXIMO:
        if menorFatorPrimo[i] == i:
            for j in range(i * i, VALORMAXIMO, i):
                if menorFatorPrimo[j] == j:
                    menorFatorPrimo[j] = i
        i += 1
 
def obterFatores(n):
    fatores = []
    if n <= 1:
        return fatores
    while n > 1:
        fatores.append(menorFatorPrimo[n])
        n //= menorFatorPrimo[n]
    return fatores

n, k = map(int, input().split())
crivo()
f = obterFatores(n)

#print(f)

for i in range(len(f)):
    if f[i] > k:
        print("Que es Obo?")
        exit()

print(len(f))
