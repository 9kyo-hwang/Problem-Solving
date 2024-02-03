input = open(0).readline

N, M = map(int, input().split())

comb = [[False] * (N + 1) for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    comb[a][b] = True
    comb[b][a] = True
    
ans = 0
for i in range(1, N - 1):
    for j in range(i + 1, N):
        for k in range(j + 1, N + 1):
            if (not comb[i][j]) and (not comb[j][k]) and (not comb[i][k]):
                ans += 1
                
print(ans)