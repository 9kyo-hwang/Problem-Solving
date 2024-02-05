input = open(0).readline

board = [list(map(int, input().split())) for _ in range(5)]
r, c = map(int, input().split())

offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]
visited = [[col == -1 for col in row] for row in board]
visited[r][c] = True


def out_of_bound(x: int, y: int) -> bool:
    return not(0 <= x <= 4 and 0 <= y <= 4)


ans = float('inf')
def dfs(x: int, y: int, step: int = 0, apple: int = 0):
    global ans
    
    if apple == 3:
        ans = min(ans, step)
        return
    
    
    for dx, dy in offset:
        nx, ny = x + dx, y + dy
        if out_of_bound(nx, ny) or visited[nx][ny]:
            continue
        
        visited[nx][ny] = True
        dfs(nx, ny, step + 1, apple + board[nx][ny])
        visited[nx][ny] = False


dfs(r, c)
print(-1 if ans == float('inf') else ans)