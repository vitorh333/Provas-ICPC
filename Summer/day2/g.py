from collections import deque
n, k = map(int, input().split())
x, a, b, c = map(int, input().split())

dq = deque()
atual = x
resp = 0

for i in range(n):
    if i > 0:
        atual = (a * atual + b) % c


    while dq and dq[-1][0] > atual:
        dq.pop()
    dq.append((atual, i))    
    
    #Fora da janela
    if dq[0][1] <= i-k:
        dq.popleft()


    if i >= k - 1:
        resp ^= dq[0][0]


print(resp)
