from collections import deque
input = open(0).readline

N, M = map(int, input().split())
maps = [list(map(int, input().split())) for _ in range(N)]
visited = [[col == 0 for col in row] for row in maps]
offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]

num_island = 0
island_numbers = {}
islands = []


def out_of_bound(x: int, y: int) -> bool:
    return not (0 <= x < N and 0 <= y < M)


def labeling(i: int, j: int):
    q = deque([(i, j)])
    maps[i][j] = num_island
    visited[i][j] = True
    island_numbers[(i, j)] = num_island
    islands.append((num_island, i, j))
    
    while q:
        x, y = q.popleft()
        
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            if out_of_bound(nx, ny) or visited[nx][ny]:
                continue
            
            maps[nx][ny] = num_island
            visited[nx][ny] = True
            island_numbers[(nx, ny)] = num_island
            islands.append((num_island, nx, ny))
            
            q.append((nx, ny))


for i in range(N):
    for j in range(M):
        if visited[i][j]:
            continue
        
        labeling(i, j)
        num_island += 1


edges = []
for src, x, y in islands:
    for dx, dy in offset:
        nx, ny, d = x + dx, y + dy, 0
        
        while True:
            if out_of_bound(nx, ny):
                break
            
            dst = island_numbers.get((nx, ny))
            if src == dst:
                break
            
            if dst == None:
                nx += dx
                ny += dy
                d += 1
                continue
            
            if d < 2:
                break
            
            edges.append((d, src, dst))
            break


parents = [i for i in range(num_island)]

def find(x: int) -> int:
    while x != parents[x]:
        parents[x] = parents[parents[x]]
        x = parents[x]
    return parents[x]
    

def union(x: int, y: int) -> bool:
    px = find(x)
    py = find(y)
    
    if px == py:
        return False
        
    if px < py:
        parents[py] = px
    else:
        parents[px] = py
        
    return True
    
cnt = num_island - 1
edges = sorted(edges, reverse=True)


ans = 0
while cnt:
    try:
        d, src, dst = edges.pop()
    except:
        ans = -1
        break
    
    if union(src, dst):
        ans += d
        cnt -= 1
        
print(ans)