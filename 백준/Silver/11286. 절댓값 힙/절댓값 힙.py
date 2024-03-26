from heapq import *
input = open(0).readline

heap = []
for _ in range(N := int(input())):
    x = int(input())
    
    if x != 0:
        heappush(heap, (abs(x), x))
        continue
    
    if not heap:
        print(0)
    else:
        print(heappop(heap)[1])