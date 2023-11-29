from collections import defaultdict, deque

input = open(0).readline

deq = deque()
counts = defaultdict(int)

X = int(input())

deq.append(X)
counts[X] = 0

while deq:
    x = deq.popleft()
    
    if x == 1:
        break
    
    if x % 3 == 0 and counts[x // 3] == 0:
        counts[x // 3] = counts[x] + 1
        deq.append(x // 3)
    if x % 2 == 0 and counts[x // 2] == 0:
        counts[x // 2] = counts[x] + 1
        deq.append(x // 2)
    if counts[x - 1] == 0:
        counts[x - 1] = counts[x] + 1
        deq.append(x - 1)
        
print(counts[1])