import sys
input = sys.stdin.readline

R, C = map(int, input().split())
board = [list(input().rstrip()) for _ in range(R)]
visited = [[False] * C for _ in range(R)]
offset = [(-1, 1), (0, 1), (1, 1)]


def out_of_bound(x: int, y: int) -> bool:
    return not(0 <= x < R and 0 <= y < C)


def dfs(x: int, y: int) -> bool:
    if out_of_bound(x, y) or board[x][y] == 'x' or visited[x][y]:
        return False
    elif y == C - 1:
        return True
    else:
        visited[x][y] = True
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            if dfs(nx, ny):
                return True

        return False
        
        
print(sum(dfs(i, 0) for i in range(R)))