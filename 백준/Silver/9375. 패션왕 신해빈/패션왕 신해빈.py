input = open(0).readline

for _ in range(int(input())): 
    d = {}
    for _ in range(int(input())):
        _, kind = input().split()
        if kind not in d:
            d[kind] = 1
        else:
            d[kind] += 1
        
    case = 1
    for value in d.values():
        case *= (value + 1)
    
    print(case - 1)