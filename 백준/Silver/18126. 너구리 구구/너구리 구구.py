import sys
from collections import deque

sys.setrecursionlimit(10**6)

input = open(0).readline

N = int(input())

tree = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    A, B, C = map(int, input().split())
    
    tree[A].append((B, C))
    tree[B].append((A, C))
    

visited = [False] * (N + 1)

max_dist = 0
def dfs(v = 1, total_dist = 0):
    global max_dist
    
    visited[v] = True
    
    max_dist = max(max_dist, total_dist)
    
    for u, d in tree[v]:
        if visited[u] == False:
            dfs(u, total_dist + d)
            

dfs()
print(max_dist)