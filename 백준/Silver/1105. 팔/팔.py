L, R = input().split()
cnt = 0

if len(L) == len(R):
    for l, r in zip(L, R):
        if l != r:
            break
        
        if l == '8':
            cnt += 1
            
print(cnt)