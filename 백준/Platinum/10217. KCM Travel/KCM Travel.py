from heapq import *
input = open(0).readline

for _ in range(T := int(input())):
    N, M, K = map(int, input().split())
    adj_list = [[] for _ in range(N + 1)]
    distances = [[float('inf')] * (M + 1) for _ in range(N + 1)]
    distances[1] = [0] * (M + 1)

    for _ in range(K):
        u, v, c, d = map(int, input().split())
        adj_list[u].append((v, c, d))
        
    def dijkstra():
        heap = [(0, 1)]
        while heap:
            du, u = heappop(heap)
            if distances[u][M] < du:
                continue
            
            for v, cv, dv in adj_list[u]:
                prev_dist = distances[v][M]
                for cost in range(0, M + 1):
                    if cost + cv > M:
                        break
                    
                    if distances[u][cost] == float('inf'):
                        continue
                    
                    if distances[u][cost] + dv < distances[v][cost + cv]:
                        distances[v][cost + cv] = distances[u][cost] + dv
                
                if prev_dist > distances[v][M]:
                    heappush(heap, (distances[v][M], v))
                    
        return print('Poor KCM' if distances[N][M] == float('inf') else distances[N][M])
        
    dijkstra()