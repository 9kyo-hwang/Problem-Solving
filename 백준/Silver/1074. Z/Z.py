import sys
input = sys.stdin.readline

N, r, c = map(int, input().split())

visited = 0
def mv(sz: int, x: int = 0, y: int = 0) -> bool:
    global visited
    
    if not (x <= r < x + sz and y <= c < y + sz):
        visited += sz * sz
        return False
    elif x == r and y == c:
        return True
    else:
        sz //= 2
        return mv(sz, x, y) or mv(sz, x, y + sz) or mv(sz, x + sz, y) or mv(sz, x + sz, y + sz)
        

mv(2 ** N)
print(visited)