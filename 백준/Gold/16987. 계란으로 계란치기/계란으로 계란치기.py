input = open(0).readline

N = int(input())
eggs = [dict] * N
for i in range(N):
    S, W = map(int, input().split())
    eggs[i] = {"S": S, "W": W}
    

def backtracking(current: int = 0, broken: int = 0) -> int:
    if current == N:  # 끝에 도달
        return broken
        
    if eggs[current]["S"] <= 0 or broken == N - 1:  # 깰 수 없는 계란 or 모든 계란이 깨짐
        return backtracking(current + 1, broken)
        
    count: int = 0
    for nxt in range(N):
        if current == nxt or eggs[nxt]["S"] <= 0:  # 같은 계란이거나 이미 깨졌다면 skip
            continue
        
        eggs[current]["S"] -= eggs[nxt]["W"]
        eggs[nxt]["S"] -= eggs[current]["W"]
        
        count = max(count, backtracking(current + 1, broken + (eggs[current]["S"] <= 0) + (eggs[nxt]["S"] <= 0)))
        
        eggs[current]["S"] += eggs[nxt]["W"]
        eggs[nxt]["S"] += eggs[current]["W"]
    return count


print(backtracking())