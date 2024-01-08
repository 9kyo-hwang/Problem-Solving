import sys

sys.setrecursionlimit(10**6)

input = open(0).readline

N, M, K = map(int, input().split())

paths = [[0] * (M + 1) for _ in range(N + 1)]

for _ in range(K):
    r, c = map(int, input().split())
    paths[r][c] = 1
    

def dfs(x: int, y: int) -> int:
    if not (1 <= x <= N and 1 <= y <= M) or paths[x][y] != 1:
        return 0
        
    paths[x][y] = 2  # visited
    return 1 + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x + 1, y) + dfs(x, y - 1)


answer = max(dfs(i, j) for j in range(1, M + 1) for i in range(1, N + 1) if paths[i][j] == 1)

print(answer)