input = open(0).readline

N = int(input())
heights = [list(map(int, input().split())) for _ in range(N)]
max_height = max(map(max, heights))
offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def out_of_bound(x: int, y: int) -> bool:
    return not (0 <= x < N and 0 <= y < N)


def dfs(x: int, y: int, height: int, visited: list):
    s = [(x, y)]
    visited[x][y] = True
    
    while s:
        x, y = s.pop()
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            if out_of_bound(nx, ny) or heights[nx][ny] <= height or visited[nx][ny]:
                continue
            
            visited[nx][ny] = True
            s.append((nx, ny))


ans = 0
for height in range(max_height + 1):
    visited = [[False] * N for _ in range(N)]
    
    cnt = 0
    for i in range(N):
        for j in range(N):
            if heights[i][j] <= height or visited[i][j]:
                continue
            
            cnt += 1
            dfs(i, j, height, visited)
            
    ans = max(ans, cnt)
    
print(ans)