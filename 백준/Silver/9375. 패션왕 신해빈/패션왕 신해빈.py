from collections import defaultdict

input = open(0).readline

for _ in range(int(input())): 
    d = defaultdict(int)
    for _ in range(int(input())):
        cloth, kind = input().split()
        d[kind] += 1
        
    case = 1
    for value in d.values():
        case *= (value + 1)
    
    print(case - 1)