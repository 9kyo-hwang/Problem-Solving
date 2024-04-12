def solution(board, moves):
    n = len(board)
    basket = [float('inf')]
    
    answer = 0
    for col in moves:
        col -= 1
        doll = 0
        
        for i in range(n):
            if board[i][col] == 0:
                continue
                
            doll = board[i][col]
            board[i][col] = 0
            break
        
        
        if doll == 0:
            continue
            
        if basket[-1] == doll:
            basket.pop()
            answer += 2
        else:
            basket.append(doll)
    

    return answer