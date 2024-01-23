input = open(0).readline

a, b = map(int, input().split())
primeCheck = [0, 0] + [1] * (b-1)
for i in range(2, b+1):
    if primeCheck[i] == 0:
        continue

    for j in range(i*i, b+1, i):
        primeCheck[j] = 0

ans = 0
for p in range(a, b+1):
    cnt = 0
    k = 2
    while k <= int(p**0.5):
        if p % k == 0:
            p //= k
            cnt += 1
        else:
            k += 1

    if p > 1:
        cnt += 1

    if primeCheck[cnt] == 1:
        ans += 1

print(ans)