input = open(0).readline

T, W = map(int, input().split())
poses = [int(input()) for _ in range(T)]
poses = [0] + [pos - 1 for pos in poses]

dp = [[[0] * 2 for _ in range(T + 1)] for _ in range(W + 1)]

for w in range(W + 1):
    dp[w][1][0] = dp[w][0][0] + (poses[1] == 0)
    if w > 0:
        dp[w][1][1] = dp[w - 1][0][0] + (poses[1] == 1)
    
    for t in range(2, T + 1):
        if w == 0:
            dp[w][t][0] = dp[w][t - 1][0] + (poses[t] == 0)
            dp[w][t][1] = dp[w][t - 1][1] + (poses[t] == 1)
            continue
        
        dp[w][t][0] = max(dp[w][t - 1][0], dp[w - 1][t - 1][1]) + (poses[t] == 0)
        dp[w][t][1] = max(dp[w - 1][t - 1][0], dp[w][t - 1][1]) + (poses[t] == 1)
        

print(max(max(dp[w][T][0], dp[w][T][1]) for w in range(W + 1)))