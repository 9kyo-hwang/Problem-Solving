input = open(0).readline

N = int(input())
paper = [list(map(int, input().split())) for _ in range(N)]
counts = {-1:0, 0:0, 1:0}

def out_of_bound(x: int, y: int) -> bool:
    return not (0 <= x < N and 0 <= y < N)
    

def is_same_color(size: int, x: int, y: int) -> bool:
    color = paper[x][y]
    
    for i in range(x, x + size):
        for j in range(y, y + size):
            if paper[i][j] != color:
                return False
                
    return True
    

def recursion(size: int = N, x: int = 0, y: int = 0):
    if out_of_bound(x, y):
        return
    elif is_same_color(size, x, y):
        counts[paper[x][y]] += 1
        return
    else:
        size //= 3
        for i in range(3):
            for j in range(3):
                recursion(size, x + i * size, y + j * size)
                

recursion()
print(*counts.values(), sep='\n')