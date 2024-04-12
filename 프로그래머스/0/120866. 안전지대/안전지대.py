def solution(board):
    n = len(board)
    board = [[-1, *line, -1] for line in board]
    board = [[-1] * (n + 2), *board, [-1] * (n + 2)]
    offset = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
    
    for x in range(1, n + 1):
        for y in range(1, n + 1):
            if board[x][y] != 1:
                continue
            
            for dx, dy in offset:
                board[x + dx][y + dy] = board[x + dx][y + dy] * 2 - 1
                    
    return sum(board, []).count(0)