import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

board = [list(map(int, input().split())) for _ in range(5)]
r, c = map(int, input().split())

offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]
visited = [[col == -1 for col in row] for row in board]


def out_of_bound(x: int, y: int) -> bool:
    return not(0 <= x <= 4 and 0 <= y <= 4)


def dfs(x: int, y: int, step: int = 0, apple: int = 0) -> int:
    if out_of_bound(x, y) or visited[x][y]:
        return -1
    elif apple == 2 and board[x][y] == 1:
        return step
    else:
        visited[x][y] = True
        min_step: int = -1
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            
            res = dfs(nx, ny, step + 1, apple + board[x][y])
            if res != -1 and (min_step == -1 or res < min_step):
                min_step = res
            
        visited[x][y] = False
        return min_step

print(dfs(r, c))