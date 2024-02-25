input = open(0).readline

n = int(input())
tree = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

a, b = map(int, input().split())
for _ in range(int(input())):
    x, y = map(int, input().split())
    tree[x].append(y)
    tree[y].append(x)
    

def dfs(src: int = a, dist: int = 0):
    if visited[src]:
        return -1
    elif src == b:
        return dist
    else:
        visited[src] = True
        ans = -1
        for dst in tree[src]:
            ans = max(ans, dfs(dst, dist + 1))
        return ans
        
print(dfs())