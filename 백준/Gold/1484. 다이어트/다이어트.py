input = open(0).readline
G = int(input())

ans = []
p, n = 1, 2    
while n**2 - (n - 1)**2 <= G:
    if n**2 - p**2 < G:
        n += 1
    elif n**2 - p**2 > G:
        p += 1
    else:
        ans.append(n)
        n += 1
        
if not ans:
    print(-1)
else:
    print(*ans, sep='\n')