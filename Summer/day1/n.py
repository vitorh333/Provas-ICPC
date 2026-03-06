while True:
    a, b, c = map(int, input().split())
    if a == 0 and b == 0 and c == 0:
        break
    else:
        if b * b == a * c:
            print("GP", c * b//a)
        else:
            print("AP", c + (b-a))
