input = open(0).readline

N, M = map(int, input().split())
S = list(map(int, input().split()))
wok_set = set(S + [S[i] + S[j] for i in range(M - 1) for j in range(i + 1, M) if S[i] + S[j] <= N])

dp = [-1] * (N + 1)  # 각 짜장면 개수 별 최소 요리 횟수
for wok in wok_set:
    dp[wok] = 1
    
for n in range(1, N + 1):
    if dp[n] > -1:
        continue
    
    min_cook_cnt = float('inf')
    for k in range(1, n):
        if dp[k] == -1 or dp[n - k] == -1:
            continue
        
        min_cook_cnt = min(min_cook_cnt, dp[k] + dp[n - k])
        dp[n] = min(dp[n], dp[k] + dp[n - k])
    
    if min_cook_cnt != float('inf'):
        dp[n] = min_cook_cnt


print(dp[N])