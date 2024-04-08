input = open(0).readline
G = int(input())
NEXT_MAX = 50001

flag = False
prev_weight, next_weight = 1, 2
while next_weight**2 - (next_weight - 1)**2 <= 100000:
    if next_weight**2 - prev_weight**2 < G:
        next_weight += 1
    elif next_weight**2 - prev_weight**2 > G:
        prev_weight += 1
    else:
        print(next_weight)
        next_weight += 1
        flag = True
        
if not flag:
    print(-1)