input = open(0).readline

A, B = map(int, input().split())

is_primes = [False, False] + [True] * (B - 1)
for i in range(2, int(B**0.5) + 1):
    if not is_primes[i]:
        continue
        
    for j in range(i * i, B + 1, i):
        is_primes[j] = False


ans = 0  
for n in range(A, B + 1):
    cnt = 0
    p = 2
    while p <= int(n**0.5):
        if n % p != 0:
            p += 1
        else:
            cnt += 1
            n //= p
            
    if p > 1:
        cnt += 1
    
    if is_primes[cnt]:
        ans += 1

        
print(ans)