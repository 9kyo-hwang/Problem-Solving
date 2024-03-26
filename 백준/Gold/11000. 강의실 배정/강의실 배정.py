from heapq import *

input = open(0).readline

N = int(input())
classes = [tuple(map(int, input().split())) for _ in range(N)]
classes.sort()

heap = [0]
for S, T in classes:
    if heap[0] <= S:
        heappop(heap)
        
    heappush(heap, T)
    
print(len(heap))