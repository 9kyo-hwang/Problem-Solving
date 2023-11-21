input = open(0).readline

G = int(input())
P = int(input())

parent = [i for i in range(100001)]

def find(x):
    while x != parent[x]:
        parent[x] = parent[parent[x]]
        x = parent[x]
        
    return parent[x]

cnt = 0
for _ in range(P):
    g = int(input())
    p = find(g)
    
    if p == 0:
        break
    
    parent[p] = p - 1
    cnt += 1
    
print(cnt)