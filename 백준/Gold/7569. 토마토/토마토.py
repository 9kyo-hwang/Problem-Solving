from collections import deque
input = open(0).readline

M, N, H = map(int, input().split())
boxes = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]

q = deque([])
num_unripe = 0
for h, height in enumerate(boxes):
    for n, row in enumerate(height):
        for m, col in enumerate(row):
            if col == 1:
                q.append((h, n, m, 0))
            elif col == 0:
                num_unripe += 1


offset = [(0, -1, 0), (0, 0, 1), (0, 1, 0), (0, 0, -1), (-1, 0, 0), (1, 0, 0)]


def out_of_bound(z, x, y):
    return not (0 <= z < H and 0 <= x < N and 0 <= y < M)
    
    
ans = 0
while q:
    z, x, y, day = q.popleft()
    ans = day
    
    for dz, dx, dy in offset:
        nz, nx, ny = z + dz, x + dx, y + dy
        if out_of_bound(nz, nx, ny) or boxes[nz][nx][ny] != 0:
            continue
        
        boxes[nz][nx][ny] = 1
        num_unripe -= 1
        q.append((nz, nx, ny, day + 1))

        
if num_unripe != 0:
    print(-1)
else:
    print(day)