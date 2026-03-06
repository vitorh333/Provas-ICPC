t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    a.sort()

    prefix = [0] * n
    prefix[0] = 1 + (2 * (n-1))

    for i in range(1, n):
        prefix[i] += prefix[i-1] + 1 + (2 * (n - i - 1))


    for i in range(n):
        if prefix[i] >= k:
            if i != 0:
                k -= prefix[i-1]
                comeco = i
                break
            else:
                comeco = i
                break


    print(prefix)
    print(k)
    
    if k == 1:
        print(2 * a[comeco])

    else:
        k -= 1
        resp = 0
        j = comeco + 1
        while k > 0:
            resp = a[comeco] + a[j]
            j += 1
            k -= 2

        print(resp)
