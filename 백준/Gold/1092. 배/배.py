input = open(0).readline

N = int(input())
crain = sorted(map(int, input().split()), reverse=True)
M = int(input())
box = sorted(map(int, input().split()), reverse=True)

def simulation() -> int:
    if box[0] > crain[0]:
        return -1
    
    tick = 0
    while True:
        if not box:
            break
        
        for i in range(len(crain)):
            for j in range(len(box)):
                if crain[i] >= box[j]:
                    del box[j]
                    break
        
        tick += 1
        
    return tick
    
print(simulation())