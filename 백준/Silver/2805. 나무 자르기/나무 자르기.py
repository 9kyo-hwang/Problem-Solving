input = open(0).readline

N, M = map(int, input().split())
trees = list(map(int, input().split()))

def check(mid):
    sum_height = 0
    for tree in trees:
        if tree > mid:
            sum_height += (tree - mid)
            
    return sum_height

lo, hi = 1, max(trees)
while lo <= hi:
    mid = (lo + hi) // 2
    
    if check(mid) < M:
        hi = mid - 1
    else:
        lo = mid + 1
        
print(hi)