n, r = map(int, input().split())
l = set(list(map(int, input().split())))
 
resp = []
for i in range(1, n+1):
    if i not in l:
        resp.append(i)
 
if len(resp) == 0:
    print("*")
else:
    print(*resp)
