from collections import deque

input = open(0).readline

N, K = map(int, input().split())
visited = [0] * 100001

visited[N] = 1
dq = deque([N])

while dq:
    pos = dq.popleft()
    
    if pos == K:
        print(visited[pos] - 1)
        break
    
    if pos * 2 <= 100000 and visited[pos * 2] == 0:
        visited[pos * 2] = visited[pos] + 1
        dq.append(pos * 2)
    
    if pos + 1 <= 100000 and visited[pos + 1] == 0:
        visited[pos + 1] = visited[pos] + 1
        dq.append(pos + 1)
    
    if pos - 1 >= 0 and visited[pos - 1] == 0:
        visited[pos - 1] = visited[pos] + 1
        dq.append(pos - 1)