input = open(0).readline

N = int(input())
S = input().rstrip()

ans = 0
for p, n in zip(S, S[1:]):
    if p == 'E' and n == 'W':
        ans += 1
        
print(ans)