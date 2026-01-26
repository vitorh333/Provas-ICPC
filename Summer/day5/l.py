n = int(input())
p = list(map(int, input().split()))

p.sort()
mediana = p[n // 2]

custo = 0
for x in p:
    custo += abs(x - mediana)

print(custo)

