input = open(0).readline

N, M = map(int, input().split())
graph = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
visited = [False] * N


def dfs(src: int, depth: int = 0) -> bool:
    if depth == 4:
        return True
        
    visited[src] = True
    for dst in graph[src]:
        if visited[dst]:
            continue
        
        if dfs(dst, depth + 1):
            return True
            
    visited[src] = False
    return False
    

def solution() -> bool:
    for node in range(N):
        if visited[node]:
            continue
        
        if dfs(node):
            return True
            
    return False


print('1' if solution() else '0')