from collections import deque
input = open(0).readline

N, S = map(int, input().split())
seq = list(map(int, input().split()))
subtotal = 0
q = deque([])

ans = 100001
for num in seq:
    q.append(num)
    subtotal += num
    
    while q and subtotal >= S:
        ans = min(ans, len(q))
        subtotal -= q.popleft()
        
print(0 if ans == 100001 else ans)