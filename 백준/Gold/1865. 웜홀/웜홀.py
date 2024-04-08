input = open(0).readline
INF = 10**9

def bellman_ford(G: list, d: list, N: int) -> bool:
    for _ in range(N - 1):
        for u in range(1, N + 1):
            for v, w in G[u]:
                if d[u] + w < d[v]:
                    d[v] = d[u] + w
                
    
    for u in range(1, N + 1):
        for v, w in G[u]:
            if d[u] + w < d[v]:
                return False  # cycle detected
            
    return True


for _ in range(TC := int(input())):
    N, M, W = map(int, input().split())
    graph = [[] for _ in range(N + 1)]
    
    for _ in range(M):
        S, E, T = map(int, input().split())
        graph[S].append((E, T))
        graph[E].append((S, T))
        
    for _ in range(W):
        S, E, T = map(int, input().split())
        graph[S].append((E, -T))
    
    distances = [INF] * (N + 1)
    result = bellman_ford(graph, distances, N)
    print('NO') if result else print('YES')