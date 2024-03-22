input = open(0).readline

N = int(input())
cards = list(map(int, input().split()))

dp = [1] * N
ans = 0
for i in range(N):
    for j in range(i):
        if cards[i] <= cards[j]:
            continue
            
        dp[i] = max(dp[i], dp[j] + 1)
    ans = max(ans, dp[i])

print(ans)