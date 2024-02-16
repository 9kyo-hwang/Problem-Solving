input = open(0).readline

N, M = map(int, input().split())
used_money = [int(input()) for _ in range(N)]

def getTakeoutCnt(mid):
    total, take_out = 0, 0 
    for used in used_money:
        if total + used > mid:
            take_out += 1
            total = 0
        total += used
    
    if total:
        take_out += 1
        
    return take_out


lo, hi = max(used_money), sum(used_money)
while lo <= hi:
    mid = (lo + hi) // 2

    if getTakeoutCnt(mid) > M:
        lo = mid + 1
    else:
        hi = mid - 1


print(lo)