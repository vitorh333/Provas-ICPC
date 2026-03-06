import math

inf = input().split()
p = int(inf[0])
a = int(inf[1])
r = float(inf[2])

xa, ya, xb, yb = map(int, input().split())

#Desce pro 0 e sobe
ra = (r / a) * ya
rb = (r / a) * yb

d1 = ra + rb

#Desce pro cara e caminha o arco
denilson = abs(xa - xb) * math.pi / p
d2 = abs(ra - rb) + min(ra, rb) * denilson
print(min(d1, d2))
