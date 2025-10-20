p = "tamocompetindo"

k = int(input())
s = input()

achei = False

for i in range(len(s) - len(p) + 1):
    cont = 0
    for j in range(len(p)):
        if s[i + j] != p[j]:
            cont += 1
    if cont <= k:
        achei = True
        break

if achei:
    print("SIM")
else:
    print("NAO")

