input = open(0).readline

N = int(input())

R, G, B = map(int, input().split())
for _ in range(N - 1):
    r, g, b = map(int, input().split())
    t1, t2, t3 = min(G, B) + r, min(R, B) + g, min(R, G) + b
    R, G, B = t1, t2, t3
    
print(min(R, G, B))