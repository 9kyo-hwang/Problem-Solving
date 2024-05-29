from heapq import *
input = open(0).readline

N, M, S, E = map(int,input().split())
S, E = S * 2, E * 2

graph = [[] for _ in range(N + 1)]
dist = [float('inf')]*(N + 1)

for _ in range(M):
    A, B, L, t1, t2 = map(int,input().split())
    graph[A].append((B, L * 2, t1))
    graph[B].append((A, L * 2, t2))


dist[1] = 0
heap = [(0, 1)]

while heap:
    tu, u = heappop(heap)

    for v, tv, t in graph[u]:
        if t == 1 and S < tu + tv and tu < E:
            traffic_jam_start = max(tu, S)

            if 2 * (tu + tv - traffic_jam_start) < (E - traffic_jam_start):
                tv += (tu + tv - traffic_jam_start)
            else:
                tv += (E - traffic_jam_start) // 2
        
        if tu + tv < dist[v]:
            dist[v] = tu + tv
            heappush(heap, (dist[v], v))


result = max(dist[1:])
print(result // 2, end='')
if result & 1:
    print('.5')