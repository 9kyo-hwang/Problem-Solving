from collections import deque
input = open(0).readline

for _ in range(C := int(input())):
    S, T = map(int, input().split())
    
    q = deque([(S, T, 0)])
    
    while q:
        src, target, cnt = q.popleft()
        
        if src - target == 0:
            print(cnt)
            break
        
        if src * 2 <= target + 3:
            q.append((src * 2, target + 3, cnt + 1))
            
        if src + 1 <= target:
            q.append((src + 1, target, cnt + 1))