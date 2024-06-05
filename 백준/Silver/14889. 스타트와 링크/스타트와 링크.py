input = open(0).readline

N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]
S_row = [sum(row) for row in S]
S_col = [sum(col) for col in zip(*S)]


def dfs(idx: int = 0, cnt: int = 0, diff: int = sum(map(sum, S))) -> int:
    if idx >= N: return float('inf')
    if cnt == N // 2: return abs(diff)
    return min(dfs(idx + 1, cnt, diff), dfs(idx + 1, cnt + 1, diff - S_row[idx] - S_col[idx]))
    
    
print(dfs())