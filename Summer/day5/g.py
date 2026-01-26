n = int(input())
l = list(map(int, input().split()))
l.sort()

soma = 0
for x in l:
    if x > soma + 1:
        break
    else:
        soma += x

print(soma + 1)
