n = int(input())
val = list(map(int, input().split()))

mx = max(val)
mn = min(val)

print((mx - mn) ** 2)

