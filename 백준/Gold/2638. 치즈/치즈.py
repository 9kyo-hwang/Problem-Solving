from collections import deque

input = open(0).readline
N, M = map(int, input().split())
is_cheese = [list(map(int, input().split())) for _ in range(N)]

times = 0
while any(1 in cheese for cheese in is_cheese):
    counts = [[0] * M for _ in range(N)]
    visited = [[False] * M for _ in range(N)]
    
    dq = deque([(0, 0)])
    visited[0][0] = True
    
    while dq:
        x, y = dq.popleft()
        
        for dx, dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nx, ny = x + dx, y + dy
            
            if not (0 <= nx < N and 0 <= ny < M) or visited[nx][ny]:
                continue
            
            if is_cheese[nx][ny]:
                counts[nx][ny] += 1
            else:
                visited[nx][ny] = True
                dq.append((nx, ny))
                
    
    for i, row in enumerate(counts):
        for j, col in enumerate(row):
            if col >= 2:
                is_cheese[i][j] = 0
                
    
    times += 1
    
print(times)