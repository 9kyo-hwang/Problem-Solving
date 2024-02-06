from collections import deque

input = open(0).readline

N, K = map(int, input().split())
visited = [-1] * 100001

visited[N] = 0
dq = deque([N])

while dq:
    pos = dq.popleft()
    
    if pos == K:
        print(visited[pos])
        break
    
    for nxt in [pos - 1, pos + 1, pos * 2]:
        if not(0 <= nxt <= 100000) or visited[nxt] != -1:
            continue
        
        visited[nxt] = visited[pos] + 1
        dq.append(nxt)