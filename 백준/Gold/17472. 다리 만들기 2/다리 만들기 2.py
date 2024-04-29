input = open(0).readline

def out_of_bound(x: int, y: int) -> bool:
    return not (0 <= x < N and 0 <= y < M)
    

def dfs(x: int, y: int):
    #global node_number
    
    visited[x][y] = True
    graph[x][y] = node_number
    islands.append((x, y, node_number))
    
    for dx, dy in offset:
        nx, ny = x + dx, y + dy
        if not out_of_bound(nx, ny) and not visited[nx][ny]:
            dfs(nx, ny)
            

def make_edges():
    #global edges
    
    for x, y, src in islands:
        for dx, dy in offset:
            nx, ny, d = x + dx, y + dy, 0
            
            while True:
                if out_of_bound(nx, ny):
                    break
                
                dst = graph[nx][ny]
                if src == dst:
                    break
                
                if dst == 0:
                    nx += dx
                    ny += dy
                    d += 1
                    continue
                
                if d < 2:
                    break
                
                edges.append((d, src, dst))
                break
            

def find(x: int) -> int:
    while x != parents[x]:
        parents[x] = parents[parents[x]]
        x = parents[x]
    return parents[x]
    

def union(x: int, y: int):
    x = find(x)
    y = find(y)
    
    if x == y:
        return False
        
    if x < y:
        parents[y] = x
    else:
        parents[x] = y
        
    return True
            
            
N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[col == 0 for col in row] for row in graph]
offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]

node_number = 1
islands = []
edges = []
            
for i in range(N):
    for j in range(M):
        if visited[i][j]:
            continue
        
        dfs(i, j)
        node_number += 1
        
make_edges()
edges.sort()

parents = [i for i in range(node_number + 1)]
ans, cnt = 0, 0

for d, src, dst in edges:
    if union(src, dst):
        ans += d
        cnt += 1
        
if cnt == node_number - 2:
    print(ans)
else:
    print(-1)