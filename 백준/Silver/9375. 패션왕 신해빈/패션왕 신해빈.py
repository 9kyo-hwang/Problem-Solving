from collections import defaultdict

input = open(0).readline

t = int(input())

for _ in range(t):
    n = int(input())
    
    d = defaultdict(int)
    for _ in range(n):
        cloth, category = input().split()
        d[category] += 1
        
    case = 1
    for key, value in d.items():
        case *= (value + 1)
    
    print(case - 1)