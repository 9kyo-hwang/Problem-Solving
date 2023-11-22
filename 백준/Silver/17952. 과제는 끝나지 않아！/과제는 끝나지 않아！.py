input = open(0).readline

stack = list()

N = int(input())
score = 0

for _ in range(N):
    n = list(map(int, input().split()))
    
    if n[0] == 0:
        if not stack:
            continue
        
        a, t = stack.pop(-1)
        t -= 1
        
        if t == 0:
            score += a
        else:
            stack.append((a, t))
    elif n[0] == 1:
        A, T = n[1], n[2]
        T -= 1
        
        if T == 0:
            score += A
        else:
            stack.append((A, T))
            
print(score)