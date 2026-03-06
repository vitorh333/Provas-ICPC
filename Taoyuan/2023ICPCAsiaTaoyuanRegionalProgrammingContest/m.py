#GABRIEL BARALHAS PORRA
import sys

t = int(input())

for _ in range(t):
    n = int(input())
    taf = list(map(int, input().split()))
    pri = list(map(int, input().split()))
    lista = []
    for i in range(len(taf)):
        lista.append((pri[i], taf[i]))

    lista.sort()
    for e in lista:
        sys.stdout.writelines(f"{e[1]} ")

    sys.stdout.writelines('\n')
