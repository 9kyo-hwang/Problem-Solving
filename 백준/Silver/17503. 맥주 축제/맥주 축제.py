from heapq import *

input = open(0).readline

N, M, K = map(int, input().split())

beers = sorted([tuple(map(int, input().split())) for _ in range(K)], key=lambda x : x[1])

heap = []
total_prefer, min_lv = 0, -1

for prefer, lv in beers:
    total_prefer += prefer
    heappush(heap, prefer)
    
    if len(heap) > N:
        total_prefer -= heappop(heap)
    
    if len(heap) == N and total_prefer >= M:
        min_lv = lv
        break
    
print(min_lv)