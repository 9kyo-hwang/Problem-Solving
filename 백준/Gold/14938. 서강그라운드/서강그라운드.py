from heapq import *

input = open(0).readline

n, m, r = map(int, input().split())
items = [0] + list(map(int, input().split()))
graph = [[] for _ in range(n + 1)]

for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a].append((b, l))
    graph[b].append((a, l))


def dijkstra(idx):
    heap = []
    dist = [float('inf')] * (n + 1)
    
    heappush(heap, [0, idx])
    dist[idx] = 0
    
    while heap:
        src_dist, src = heappop(heap)
        for dst, dst_dist in graph[src]:
            if src_dist + dst_dist < dist[dst]:
                dist[dst] = src_dist + dst_dist
                heappush(heap, [dist[dst], dst])
    
    return sum(items[i] for i in range(1, n + 1) if dist[i] <= m)


print(max(dijkstra(i) for i in range(1, n + 1)))