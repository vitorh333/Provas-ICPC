import math

a, b, c, d = map(int, input().split())
 
if b > a:
    a, b = b, a
if d > c:
    c, d = d, c
 
if a >= c and b >= d:
    print("YES")
    exit()
 
if b < d:
    print("NO")
    exit()
 
found = False
for l1 in range(a):
    if found:
        break
    for l2 in range(b):     
        dig1 = math.sqrt((l1 * l1) + (l2 * l2))

        co = (c * c) -(b - l2) ** 2

        if co >= 0:
            co = math.sqrt(co)
        
            ca = (d * d) -(a - co) ** 2
        
            if ca >= 0:
                ca = math.sqrt(ca)

                cd = (c * c) -(b - ca) ** 2

                if cd >= 0:
                    cd = math.sqrt(cd)

                    ce = -(cd * cd) + (c*c)

                    if ce >= 0:
                        ce = math.sqrt(ce)


                        if (dig1 >= d) and (a >= co) and (b >= ca + cd) and (a >= ce + l1):
                                #print(l1, l2)
                                print("YES")
                                found = True
                                break

if not found:
    print("NO")
