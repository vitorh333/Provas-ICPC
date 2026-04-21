n = int(input())
x = list(map(int, input().split()))
 
s = sum(x)
if s % 3 != 0:
    print(0)
    exit()
 
target1 = s // 3
target2 = 2 * s // 3
 
x = x + x
 
pref = [0] * (2*n + 1)
for i in range(2*n):
    pref[i+1] = pref[i] + x[i]
 
 
res = 0
j = 0
k = 0
 
for i in range(n):
    while j < i or pref[j] - pref[i] < target1:
        j += 1
    
    while k < j or pref[k] - pref[i] < target2:
        k += 1
    
    if pref[j] - pref[i] == target1 and pref[k] - pref[i] == target2:
        res += 1
 
 
print(res // 3)
