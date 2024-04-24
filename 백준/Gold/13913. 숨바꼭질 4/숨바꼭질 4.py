from collections import deque
from sys import stdin, setrecursionlimit
setrecursionlimit(10**6)
input = stdin.readline

n, k = map(int, input().split())
distances = [100001] * (100001)
parents = [i for i in range(100001)]

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
        

def dfs(x: int = k):
    if(x == n):
        print(x, end=' ')
        return
    
    dfs(parents[x])
    print(x, end=' ')
    
dfs()