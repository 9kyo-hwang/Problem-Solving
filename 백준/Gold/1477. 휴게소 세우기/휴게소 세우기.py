input = open(0).readline

N, M, L = map(int, input().split())
area_list = [0] + sorted(map(int, input().split())) + [L]

low, high = 1, L - 1
answer = 1001

def can_build(mid: int):
    num_can_build = 0
    for i in range(1, len(area_list)):
        dist = area_list[i] - area_list[i - 1]
        num_can_build += dist // mid
        if dist % mid == 0:
            num_can_build -= 1
            
    return num_can_build <= M

while low <= high:
    mid = (low + high) // 2
    
    if can_build(mid):
        answer = min(answer, mid)
        high = mid - 1
    else:
        low = mid + 1
        
print(answer)