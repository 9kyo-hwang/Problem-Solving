from collections import deque
input = open(0).readline

n, k = map(int, input().split())
distances = [100001] * 100001
parents = [-1] * 100001

q = deque([n])
distances[n] = 0

def out_of_bound(x: int) -> bool:
    return not (0 <= x <= 100000)


while q:
    x = q.popleft()
    if x == k:
        print(distances[x])
        break
    
    for nx in (x * 2, x - 1, x + 1):
        if out_of_bound(nx) or distances[nx] < distances[x] + 1:
            continue
        
        distances[nx] = distances[x] + 1
        parents[nx] = x
        q.append(nx)
        

paths = deque([k])
while parents[k] != -1:
    k = parents[k]
    paths.appendleft(k)
    
print(' '.join(map(str, paths)))