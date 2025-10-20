def multiplicaMatrizes(m1, m2, MOD):
    resp = [[0 for i in range(len(m2[0]))] for i in range(len(m1))]

    for i in range(len(m1)):
        for j in range(len(m2[0])):
            for k in range(len(m1[0])):
                resp[i][j] = (resp[i][j] + (m1[i][k] * m2[k][j])) % MOD

    return resp


def expoRapida(matriz, exp, MOD):
    resp = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]

    while exp > 0:
        if(exp % 2 == 1):
            resp = multiplicaMatrizes(resp, matriz, MOD)
        matriz = multiplicaMatrizes(matriz, matriz, MOD)
        exp //= 2

    return resp

MOD = 10**9 + 7
n = int(input())

if n == 1:
    print(2)
elif n == 2:
    print(3)
else:
    estado = [[3], [2], [1], [3]]
    m = [[3, 2, 1, 1], [1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, 1]]

    resp = expoRapida(m, n-1, MOD)
    resp = multiplicaMatrizes(resp, estado, MOD)

    print(resp[1][0])
