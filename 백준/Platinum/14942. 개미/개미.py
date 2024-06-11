from heapq import *
from collections import deque


def binary_search(paths: deque, energy: int) -> int:
    lo, hi = -1, len(paths)
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if paths[0][1] - paths[mid][1] <= energy:
            lo = mid
        else:
            hi = mid
            
    return 0 if lo == -1 else lo
    

def dijkstra(heap: list, distances: list, parents: list, tree: list):
    heappush(heap, (0, 1))
    distances[1] = 0
    
    while heap:
        du, u = heappop(heap)
        
        if distances[u] < du:
            continue
        
        for v, dv in tree[u]:
            if du + dv < distances[v]:
                distances[v] = du + dv
                parents[v] = u
                heappush(heap, (distances[v], v))

    
def main():
    input = open(0).readline
    
    n = int(input())
    energy_of_ants = [0] + [int(input()) for _ in range(n)]
    tree = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        a, b, c = map(int, input().split())
        tree[a].append((b, c))
        tree[b].append((a, c))
                
    
    heap = []
    distances = [float('inf')] * (n + 1)
    parents = [0] * (n + 1)
    
    dijkstra(heap, distances, parents, tree)

    answer = [0] * (n + 1)
    for i in range(2, n + 1):
        if len(tree[i]) > 1:
            continue
        
        node = i
        paths = deque()
        while node != 0:
            paths.append((node, distances[node]))
            node = parents[node]
        
        while paths:
            u, du = paths[0]
            if answer[u] != 0:
                paths.popleft()
                continue
            
            answer[u] = paths[binary_search(paths, energy_of_ants[u])][0]
            paths.popleft()
    
    print('\n'.join(map(str, answer[1:])))


if __name__ == "__main__":
    main()