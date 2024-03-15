from collections import deque
input = open(0).readline

N, k = map(int, input().split())
lines = [list(map(int, input().rstrip())) for _ in range(2)]


def out_of_bound(tick, c) -> bool:
    return not (tick < c < N)


def bfs() -> bool:
    q = deque([(0, 0)])
    for tick in range(0, N):
        for _ in range(len(q)):
            r, c = q.popleft()
            
            for nr, nc in ((r, c + 1), (r, c - 1), (r ^ 1, c + k)):
                if nc >= N:
                    return True
                
                if out_of_bound(tick, nc) or lines[nr][nc] == 0:
                    continue
                
                lines[nr][nc] = 0
                q.append((nr, nc))
    

print(1 if bfs() else 0)