from collections import deque

input = open(0).readline

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    priority_list = list(map(int, input().split()))
    
    deq = deque([(i, priority_list[i]) for i in range(N)])  # index, priority
    
    count = 1
    while True:
        top = max(deq, key = lambda x: x[1])
        front = deq.popleft()
        
        if top[1] > front[1]:
            deq.append(front)
        elif front[0] == M:
            break
        else:
            count += 1
    print(count)