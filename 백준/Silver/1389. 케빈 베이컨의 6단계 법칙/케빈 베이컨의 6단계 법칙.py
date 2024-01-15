input = open(0).readline
INF = float('inf')

N, M = map(int, input().split())

dp = [[INF] * (N + 1) for _ in range(N + 1)]
for i in range(1, N + 1):
    dp[i][i] = 0  # self distance = 0
    
for _ in range(M):
    A, B = map(int, input().split())
    dp[A][B] = dp[B][A] = 1  # A -> B = B -> A
    

for k in range(1, N + 1):  # via node
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            # distance(i -> j) vs distance(i -> k) + distance(k -> j)
            # min: update unconnected(INF) node to connected
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
            

min_idx = min(range(1, N + 1), key=lambda i: sum(dp[i][1:]))
print(min_idx)