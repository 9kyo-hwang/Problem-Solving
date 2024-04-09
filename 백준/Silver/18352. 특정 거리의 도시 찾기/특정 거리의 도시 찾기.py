from collections import deque
input = open(0).readline

N, M, K, X = map(int, input().split())
G = [[] for _ in range(N + 1)]

for _ in range(M):
    A, B = map(int, input().split())
    G[A].append(B)
    
d = [float('inf')] * (N + 1)
q = deque([X])
d[X] = 0

while q:
    u = q.popleft()
    for v in G[u]:
        if d[u] + 1 < d[v] and d[u] + 1 <= K:
            d[v] = d[u] + 1
            q.append(v)
            

ans = [city for city, dist in enumerate(d) if dist == K]
if not ans:
    print(-1)
else:
    print(' '.join(map(str, ans)))