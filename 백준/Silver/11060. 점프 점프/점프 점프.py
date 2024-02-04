input = open(0).readline

N = int(input())
A = list(map(int, input().split()))
dp = [0] + [-1] * (N - 1)

for i in range(N):
    if dp[i] == -1:
        break
        
    for jump in range(1, A[i] + 1):
        if i + jump < N and dp[i + jump] == -1:
            dp[i + jump] = dp[i] + 1
            
print(dp[-1])