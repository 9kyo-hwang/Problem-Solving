from collections import deque

input = open(0).readline

N, M, V = map(int, input().split())

graph = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
[graph[i].sort() for i in range(1, N + 1)]

visited = [False] * (N + 1)


def dfs(v: int = V):
    if visited[v]:
        return
    
    visited[v] = True;
    print(v, end=' ')
    
    for u in graph[v]:
        dfs(u)


dfs()
print()

visited = [False] * (N + 1)


def bfs(v: int = V):
    dq = deque([v])
    visited[v] = True
    
    while dq:
        front = dq.popleft()
        print(front, end=' ')
        
        for u in graph[front]:
            if visited[u] == False:
                visited[u] = True
                dq.append(u)
                
                
bfs()