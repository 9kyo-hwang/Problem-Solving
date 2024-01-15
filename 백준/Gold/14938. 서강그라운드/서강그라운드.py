input = open(0).readline
INF = float('inf')


def main():
    n, m, r = map(int, input().split())
    items = [0] + list(map(int, input().split()))
    
    dp = [[INF] * (n + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i][i] = 0
        
    for _ in range(r):
        a, b, l = map(int, input().split())
        dp[a][b] = dp[b][a] = l
        
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
                
    ans = 0
    for i in range(1, n + 1):
        total = 0
        for j in range(1, n + 1):
            if dp[i][j] <= m:
                total += items[j]
        ans = max(ans, total)
    
    print(ans)

if __name__ == "__main__":
    main()