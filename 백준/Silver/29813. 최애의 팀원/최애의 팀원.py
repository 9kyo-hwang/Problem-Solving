from collections import deque

input = open(0).readline

N: int = int(input())
deq = deque()

for _ in range(N):
    initial, number = input().split()
    deq.append((initial, int(number)))
    
    
while len(deq) > 1:
    front_init, front_num = deq.popleft()
    pos: int = (front_num - 1) % len(deq)
    del deq[pos]
    
    deq.rotate(-pos)


print(deq[0][0])