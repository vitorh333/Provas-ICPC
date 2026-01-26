t = int(input())

for _ in range(t):
    s = input().strip()

    if len(s) % 3 == 1:
        s = "0" + s
    if len(s) % 3 == 2:
        s = "00" + s
    
    soma = 0
    fat = 1

    for i in range(len(s) - 3, -1, -3):
        bloco = int(s[i:i+3])
        soma += fat * bloco
        fat *= -1

    if soma % 13 == 0:
        print(abs(soma), "YES")
    else:
        print(abs(soma), "NO")

