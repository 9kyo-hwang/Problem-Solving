from heapq import heappush, heappop

input = open(0).readline

offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]

i = 1
while (N := int(input())) and N != 0:
    cave = [list(map(int, input().split())) for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    
    heap = []
    heappush(heap, (cave[0][0], 0, 0))
    visited[0][0] = True
    
    while heap:
        cost, x, y = heappop(heap)
        if x == N - 1 and y == N - 1:
            print("Problem {}: {}".format(i, cost))
            break
        
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            if not(0 <= nx < N and 0 <= ny < N) or visited[nx][ny]:
                continue
                
            visited[nx][ny] = True
            heappush(heap, (cost + cave[nx][ny], nx, ny))
            
    i += 1