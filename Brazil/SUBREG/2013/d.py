from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)

def backtrack(pos, aux, usados):
    if pos == len(aux):
        return True



    for s in aux[pos]:
        if usados.isdisjoint(s):
            if backtrack(pos + 1, aux, usados | s):
                return True

    return False    


def testamask(a, b):
    aux = defaultdict(list)

    for x in range(len(b)):
        for i in range(1 << len(a)):
            p = set()
            soma  = 0

            for j in range(len(a)):
                if(1 << j) & i != 0:
                    p.add(j)
                    soma += a[j]

            if soma == b[x]:
                aux[x].append(p)

    if(aux) == {}: return False
    for x in aux:
        if aux[x] == {}: return False

    

    return backtrack(0, aux, set())
        

n = int(input())
a = list(map(int, input().split()))
s = int(input())
b = list(map(int, input().split()))

v = testamask(a, b)
if v: print("S")
else: print("N")

