input = open(0).readline

N = int(input())
S, W = [0] * N, [0] * N
for i in range(N):
    s, w = map(int, input().split())
    S[i], W[i] = s, w
    

def backtracking(current: int = 0, broken: int = 0) -> int:
    if broken == N - 1 or current == N:  # 모든 계란이 깨졌거나 끝까지 왔다면면
        return broken
        
    if S[current] <= 0:  # 이미 깨짐
        return backtracking(current + 1, broken)
        
    count: int = 0
    for nxt in range(N):
        if current == nxt or S[nxt] <= 0:  # 같은 계란이거나 이미 깨졌다면 skip
            continue
        
        S[current] -= W[nxt]
        S[nxt] -= W[current]
        
        count = max(count, backtracking(current + 1, broken + (S[current] <= 0) + (S[nxt] <= 0)))
        
        S[current] += W[nxt]
        S[nxt] += W[current]
    
    return count

    
print(backtracking())