from collections import deque

input = open(0).readline

N, M = map(int, input().split())
is_cheese = [list(map(int, input().split())) for _ in range(N)]

offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]
is_outside = [[False] * M for _ in range(N)]
is_outside[0][0] = True

outside_q = deque([(0, 0)])
contact_q = deque()
times = 0

def is_out_of_bound(x, y):
   return not (0 <= x < N and 0 <= y < M) 


def expand_outside():
    while outside_q:
        x, y = outside_q.popleft()
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            
            if is_out_of_bound(nx, ny):
                continue
            
            if (is_cheese[nx][ny] == 0) and (not is_outside[nx][ny]):
                is_outside[nx][ny] = True
                outside_q.append((nx, ny))
            elif is_cheese[nx][ny]:
                contact_q.append((nx, ny))
            
            
def melt_cheese():
    melted_cheese = set()
    
    while contact_q:
        x, y = contact_q.popleft()
        
        cnt = 0
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
        
            if is_outside[nx][ny]:
                cnt += 1
        
        if cnt >= 2:
            melted_cheese.add((x, y))
            
    for x, y in melted_cheese:
        is_outside[x][y] = True
        is_cheese[x][y] = 0
        outside_q.append((x, y))
    
times = 0
while True:
    expand_outside()
    
    if not contact_q:
        break
    
    melt_cheese()
    
    times += 1
    
print(times)