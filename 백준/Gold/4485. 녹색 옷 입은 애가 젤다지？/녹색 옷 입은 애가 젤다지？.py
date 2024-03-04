from heapq import *
input = open(0).readline

offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]
cnt = 1

while (N := int(input())):
    cave = [list(map(int, input().split())) for _ in range(N)]
    
    heapify(heap := [(cave[0][0], 0, 0)])
    cave[0][0] = -1
    
    while heap:
        cost, x, y = heappop(heap)
        if x == N - 1 and y == N - 1:
            print("Problem {}: {}".format(cnt, cost))
            break
        
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            if not (0 <= nx < N and 0 <= ny < N) or cave[nx][ny] == -1:
                continue
            
            heappush(heap, (cost + cave[nx][ny], nx, ny))
            cave[nx][ny] = -1
    
    cnt += 1