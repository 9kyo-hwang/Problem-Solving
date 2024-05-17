input = open(0).readline

V, E = map(int, input().split())

parents = [i for i in range(V + 1)]
edges = [tuple(map(int, input().split())) for _ in range(E)]
edges.sort(key=lambda edge: edge[2])

def find(x: int) -> int:
    while x != parents[x]:
        parents[x] = parents[parents[x]]
        x = parents[x]
    return parents[x]
    

def union(u: int, v: int):
    x = find(u)
    y = find(v)
    
    if x < y:
        parents[y] = x
    else:
        parents[x] = y


mst = 0
for x, y, d in edges:
    if find(x) != find(y):
        union(x, y)
        mst += d
        
print(mst)