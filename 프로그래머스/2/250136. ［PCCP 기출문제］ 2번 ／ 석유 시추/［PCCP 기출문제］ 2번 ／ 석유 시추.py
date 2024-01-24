import sys
sys.setrecursionlimit(10**6)

n, m = 0, 0
cols = set()

def dfs(land, x, y):
    if not (0 <= x < n and 0 <= y < m) or land[x][y] != 1:
        return 0
    
    land[x][y] = 2
    cols.add(y)
    return 1 + dfs(land, x - 1, y) + dfs(land, x, y + 1) + dfs(land, x + 1, y) + dfs(land, x, y - 1)


def solution(land):
    global n, m, cols
    n, m = len(land), len(land[0])
    
    areas = [0] * m
    for j in range(m):
        for i in range(n):
            if land[i][j] != 1:
                continue
        
            cols.clear()
            cnt = dfs(land, i, j)
            for col in cols:
                areas[col] += cnt
        
    return max(areas)