t = int(input())
for _ in range(t):
    n = int(input())
    resp = [0] * n

    if n % 2 == 1:
        resp[n//2] = 1

        impar = 3
        par = 2

        for i in range(n//2):
            resp[i] = par
            par += 2

        for i in range(n//2 + 1, n):
            resp[i] = impar
            impar += 2

    else:

        resp[n//2-1] = 1

        resp[n-1] = n
        par = n-2
        impar = n-1
        i = n//2 - 2
        j = n//2
        
       

        while i >= 0 and j < n-1:
            if j % 2 == 1:
                resp[j] = impar
                impar -= 2
                j += 1
            else:
                resp[j] = par
                par -= 2
                j += 1

            if i % 2 == 1:
                resp[i] = par
                par -= 2
                i-=1

            else:
                resp[i] = impar
                impar -= 1
                i-=1
    print(*resp)
