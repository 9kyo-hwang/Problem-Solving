from collections import Counter

input = open(0).readline

T: int = int(input())

for _ in range(T):
    W: str = input()
    K: int = int(input())
    
    alpha_dict = Counter(W[:-1])
    minlen: int = 10001
    maxlen: int = 0
    
    for left in range(len(W)):
        if alpha_dict[W[left]] < K:
            continue
        
        sublen: int = 0
        for right in range(left, len(W)):
            if W[left] == W[right]:
                sublen += 1
            
            if sublen == K:
                minlen = min(minlen, right - left + 1)
                maxlen = max(maxlen, right - left + 1)
                break
    
    if minlen == 10001 or maxlen == 0:
        print(-1)
    else:
        print(minlen, maxlen)