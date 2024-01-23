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
    div_list = []
    div = 2
    while div <= sqrt_x:
        if x % div != 0:
            div += 1
        else:
            div_list.append(div)
            x //= div
            
    if x > 1:
        div_list.append(x)
        
    ans += 1 if is_primes[len(div_list)] else 0
    
print(ans)