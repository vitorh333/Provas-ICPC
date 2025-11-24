
MOD = 10**9 + 7
SIZE = 20

def mult_matriz(A, B):
    C = [[0] * SIZE for _ in range(SIZE)]
    for i in range(SIZE):
        for j in range(SIZE):
            for k in range(SIZE):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
    return C

def exp_matrizes(A, n):
    res = [[0] * SIZE for _ in range(SIZE)]
    for i in range(SIZE):
        res[i][i] = 1
    base = A
    while n > 0:
        if n % 2 == 1:
            res = mult_matriz(res, base)
        base = mult_matriz(base, base)
        n //= 2
    return res

M = [[0] * SIZE for _ in range(SIZE)]
    
M[0][5] = 3
M[0][9] = 3
M[0][13] = 3
M[0][17] = 3
    
for i in range(1, SIZE):
    M[i][i-1] = 1

t = int(input())    
results = []
for _ in range(t):
    n = int(input())    
    M_N = exp_matrizes(M, n)
    total = sum(M_N[i][0] for i in range(SIZE)) % MOD    
    results.append(str(total)) 
print("\n".join(results))

