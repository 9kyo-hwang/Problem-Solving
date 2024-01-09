from collections import deque

input = open(0).readline

N, M = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(N)]

dq = deque([(0, 0)])

offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]

while dq:
    x, y = dq.popleft()
    
    if x == N - 1 and y == M - 1:
        break
    
    for dx, dy in offset:
        nx, ny = x + dx, y + dy
        if not(0 <= nx < N and 0 <= ny < M) or maze[nx][ny] != 1:
            continue
        
        maze[nx][ny] = maze[x][y] + 1
        dq.append((nx, ny))
        
print(maze[N - 1][M - 1])