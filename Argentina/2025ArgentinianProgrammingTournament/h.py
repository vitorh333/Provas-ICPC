import math

def isPrime(k):
    if k == 0 or k == 1: return False
    if k == 2: return True
    if k % 2 == 0: return False

    t = int(math.sqrt(k)) + 1

    for i in range(3, t, 2):
        if k % i == 0:
            return False

    return True

n = int(input())
divs = list(map(int, input().split()))
divs = set(divs)
cand = math.lcm(*divs)


if cand == 1:
    print("*")

elif 1 not in divs:
    print(cand, 1)

elif cand not in divs:
    print(cand, cand)

else:

    for k in divs:
        if cand // k not in divs:
            print(cand, cand // k)
            exit()

    if math.sqrt(cand) == int(math.sqrt(cand)) and int(math.sqrt(cand)) not in divs:
        print(cand, int(math.sqrt(cand)))
        exit()

    primos = []

    for k in divs:
        if isPrime(k):
            primos.append(k)
    
    primos.sort()

    for p in primos:
        if cand * p not in divs:
            print(cand * p, cand * p)
            exit()
