input = open(0).readline
INF = 10**9

def bellman_ford(G: list, d: list, N: int):
    for _ in range(N - 1):
        for u, v, w in G:
            if d[u] + w < d[v]:
                d[v] = d[u] + w
                
    
    for u, v, w in G:
        if d[u] + w < d[v]:
            return False
            
    return True


for _ in range(TC := int(input())):
    N, M, W = map(int, input().split())
    graph = []
    
    for _ in range(M):
        S, E, T = map(int, input().split())
        graph.append((S, E, T))
        graph.append((E, S, T))
        
    for _ in range(W):
        S, E, T = map(int, input().split())
        graph.append((S, E, -T))
    
    distances = [INF] * (N + 1)
    result = bellman_ford(graph, distances, N)
    print('NO') if result else print('YES')