from heapq import *
input = open(0).readline

def dijkstra(size):
    heapify(hq := [(cave[0][0], 0, 0)])
    cave[0][0] = -1
    
    while hq:
        cost, x, y = heappop(hq)
        for dx, dy in [(-1,0),(0,1),(1,0),(0,-1)]:
            nx, ny = x+dx, y+dy
            
            if nx == ny == n-1:
                return cost+cave[nx][ny]
            
            if nx < 0 or ny < 0 or nx == size or ny == size or cave[nx][ny] == -1:
                continue

            heappush(hq, (cost+cave[nx][ny],nx,ny))
            cave[nx][ny] = -1
    
cnt = 0
while (n:=int(input())):
    cnt += 1
    cave = [list(map(int,input().split())) for _ in range(n)]
    
    print("Problem {}: {}".format(cnt, dijkstra(n)))