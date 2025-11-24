from collections import defaultdict
 
n, x = map(int, input().split())
v = list(map(int, input().split()))
freq = defaultdict(int)
 
for e in v:
    freq[e] += 1
 
res = []
 
for i in range(n):
    colocou = False
    prev = res[-1] if i > 0 else None
    
    for e in list(freq.keys()):
        
        if prev is None or prev + e != x:
            res.append(e)
 
            freq[e] -= 1
            if freq[e] == 0:
                del freq[e]
 
            colocou = True
            break
    
    print(res)

    if not colocou:
        print("*")
        exit()
 
print(*res)
