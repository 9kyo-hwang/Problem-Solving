input = open(0).readline

def dfs(n: int, k: int) -> int:
    if k <= n:  # only X - 1
        return n - k
    elif k == 1:  # cannot go back more
        return 1
    elif k % 2 == 0:  # X + 1 vs X * 2
        return min(k - n, dfs(n, k // 2) + 1)
    else:  # X - 1 vs X + 1
        return min(dfs(n, k + 1) + 1, dfs(n, k - 1) + 1)

N, K = map(int, input().split())
print(dfs(N, K))