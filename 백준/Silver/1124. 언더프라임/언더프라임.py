import math
input = open(0).readline

A, B = map(int, input().split())

is_primes = [True] * (B + 1)
is_primes[0] = is_primes[1] = False

for i in range(2, int(math.sqrt(B)) + 1):
    if is_primes[i]:
        for j in range(i * i, B + 1, i):
            is_primes[j] = False
            
ans = 0  
for x in range(A, B + 1):
    sqrt_x = int(math.sqrt(x))
    div, cnt = 2, 0
    while div <= sqrt_x:
        if x % div != 0:
            div += 1
        else:
            cnt += 1
            x //= div
            
    if x > 1:
        cnt += 1
        
    ans += 1 if is_primes[cnt] else 0
    
print(ans)