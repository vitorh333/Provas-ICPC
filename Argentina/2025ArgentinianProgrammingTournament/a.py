s = input()
achei = False

for i in range(1 << 10):
    cand = ""

    for j in range(10):
        if(1 << j) & i != 0:
            cand += s[j]

    if cand == "TAP":
        achei = True

if achei:
    print("S")
else:
    print("N")

