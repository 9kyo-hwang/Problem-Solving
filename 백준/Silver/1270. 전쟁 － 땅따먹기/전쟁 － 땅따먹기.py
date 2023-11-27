from collections import Counter

input = open(0).readline

n = int(input())

for _ in range(n):
    info = list(map(int, input().split()))
    land, soldier = info[0], Counter(info[1:])
    
    most_common = soldier.most_common(1)
    if most_common[0][1] > land // 2:
        print(most_common[0][0])
    else:
        print('SYJKGW')