input = open(0).readline
MOD = 10**9 + 7

def pow(base: int, exp: int, mod: int):
    if exp == 1:
        return base
        
    next_base = pow(base, exp // 2, mod)
    if exp % 2 == 0:
        return next_base * next_base % mod
    else:
        return next_base * next_base * base % mod

for _ in range(T := int(input())):
    N = int(input())
    print(1 if N <= 2 else pow(2, N - 2, MOD))