import sys
from heapq import heapify, heappop, heappush

input = sys.stdin.readline

V, E = map(int, input().split())
K = int(input())
graph = [[] for _ in range(V + 1)]

for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

INF = float('inf')
distances = [INF] * (V + 1)
distances[K] = 0

queue = [(0, K)]
heapify(queue)

while queue:
    du, u = heappop(queue)
    if distances[u] < du:
        continue
    
    for v, dv in graph[u]:
        if du + dv < distances[v]:
            distances[v] = du + dv
            heappush(queue, (distances[v], v))
            
for distance in distances[1:]:
    print('INF' if distance == INF else distance)