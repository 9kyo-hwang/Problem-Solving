input = open(0).readline

R, C = map(int, input().split())
board = [list(input().rstrip()) for _ in range(R)]


def out_of_bound(x: int, y: int) -> bool:
    return not(0 <= x < R and 0 <= y < C)


def dfs(x: int, y: int) -> int:
    if out_of_bound(x, y) or board[x][y] == 'x':
        return 0
    elif y == C - 1:
        return 1
    else:
        board[x][y] = 'x'
        return dfs(x - 1, y + 1) or dfs(x, y + 1) or dfs(x + 1, y + 1)
        
        
print(sum(dfs(i, 0) for i in range(R)))