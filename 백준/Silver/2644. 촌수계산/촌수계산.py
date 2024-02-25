input = open(0).readline

n = int(input())
a, b = map(int, input().split())
m = int(input())

tree = [[] for _ in range(n + 1)]
dists = [-1] * (n + 1)
dists[a] = 0

for _ in range(m):
    x, y = map(int, input().split())
    tree[x].append(y)
    tree[y].append(x)
    

def dfs(src: int = a):
    for dst in tree[src]:
        if dists[dst] == -1:
            dists[dst] = dists[src] + 1
            dfs(dst)
        
dfs()
print(dists[b])