from heapq import *
from collections import defaultdict
input = open(0).readline

N, M, S, E = map(int,input().split())
S, E = S * 2, E * 2

graph = defaultdict(list)
dist = [float('inf')]*(N + 1)

for _ in range(M):
    A, B, L, t1, t2 = map(int,input().split())
    graph[A].append((B, L * 2, t1))
    graph[B].append((A, L * 2, t2))


dist[1] = 0
heap = [(0, 1)]

while heap:
    du, u = heappop(heap)
    if dist[u] < du:
        continue

    for v, dv, t in graph[u]:
        if t == 0 and du + dv < dist[v]:
            dist[v] = du + dv
            heappush(heap, (dist[v], v))
            continue
            
        if t == 1 and S < du + dv and du < E:
            traffic_jam_start = max(du, S)

            if 2 * (du + dv - traffic_jam_start) < (E - traffic_jam_start):
                dv += (du + dv - traffic_jam_start)
            else:
                dv += (E - traffic_jam_start) // 2
        
        if du + dv < dist[v]:
            dist[v] = du + dv
            heappush(heap, (dist[v], v))


result = max(dist[1:])
print(result // 2, end='')
if result & 1:
    print('.5')