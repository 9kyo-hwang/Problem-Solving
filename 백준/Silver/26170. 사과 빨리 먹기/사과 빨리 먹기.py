import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

board = [list(map(int, input().split())) for _ in range(5)]
offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]

r, c = map(int, input().split())


def out_of_bound(x: int, y: int) -> bool:
    return not(0 <= x <= 4 and 0 <= y <= 4)


def dfs(x: int, y: int, step: int = 0, apple: int = 0) -> int:
    if out_of_bound(x, y) or board[x][y] == -1:
        return float('inf')
    elif apple == 2 and board[x][y] == 1:
        return step
    else:
        is_apple = board[x][y] == 1
        board[x][y] = -1
        
        min_step: int = float('inf')
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            
            min_step = min(min_step, dfs(nx, ny, step + 1, apple + is_apple))
            
        board[x][y] = 1 if is_apple else 0
        return min_step
    
ans = dfs(r, c)
print(-1 if ans == float('inf') else ans)