from collections import deque
input = open(0).readline

N = int(input())
q = deque(list(map(int, input().split())))

score = 0
while len(q) > 1:
    x, y = q.popleft(), q.popleft()
    score += x * y
    q.append(x + y)
    
print(score)