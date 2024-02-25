from heapq import *
input = open(0).readline

for _ in range(C := int(input())):
    S, T = map(int, input().split())
    heap = [(0, S, T)]
    
    while heap:
        cnt, s, t = heappop(heap)
        
        if s == t:
            print(cnt)
            break
        
        for ns, nt in [(s * 2,  t + 3), (s + 1, t)]:
            if ns > nt:
                continue
            
            heappush(heap, (cnt + 1, ns, nt))