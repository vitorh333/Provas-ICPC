import sys
input = sys.stdin.readline

k = int(input())
ing = list(map(int, input().split()))

n = int(input())
time = [0] * k
m = []

for i in range(n):
    pk = list(map(int, input().split()))
    m.append(pk)
    for s in range(len(pk)):
        time[s] += pk[s]

resp1 = 10**18

for i in range(len(time)):
    if time[i] != 0:
        resp1 = min(resp1, (ing[i] // time[i]) + 1)

for i in range(k):
    ing[i] -= (resp1 - 1) * time[i]

acabou = False
resp2 = -1
#print(ing)

for i in range(len(m)):
    for j in range(len(m[i])):
        if m[i][j] <= ing[j]:
            ing[j] -= m[i][j]

        else:
            acabou = True
            resp2 = i + 1
            break
    if acabou:
        break

print(resp1, resp2)
#print(ing)
#print(time)
