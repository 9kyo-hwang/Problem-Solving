from collections import defaultdict

input = open(0).readline

T: int = int(input())

for _ in range(T):
    W: str = input()
    K: int = int(input())
    
    alpha_indices = defaultdict(list)
    for i in range(len(W)):
        alpha_indices[W[i]].append(i)
    
    minlen: int = 10001
    maxlen: int = 0
    for indices in alpha_indices.values():
        if len(indices) < K:
            continue
        
        l: int = 0
        r: int = K - 1
        while r < len(indices):
            strlen: int = indices[r] - indices[l] + 1
            minlen = min(minlen, strlen)
            maxlen = max(maxlen, strlen)
            
            l += 1
            r += 1
    
    if minlen == 10001:
        print(-1)
    else:
        print(minlen, maxlen)