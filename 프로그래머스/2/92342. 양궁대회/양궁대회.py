from itertools import product

def solution(n, info):
    info.reverse()
    answer = [-1]
    max_diff = 0
    
    for case in product([True, False], repeat=11):
        total_arrows = sum(num_arrow + 1 for num_arrow, ryan_won in zip(info, case) if ryan_won)
        if total_arrows > n:
            continue
        
        ryan = sum(i for i, ryan_won in enumerate(case) if ryan_won)
        apeach = sum(i for i, (ryan_won, num_arrow) in enumerate(zip(case, info)) if (not ryan_won) and (num_arrow > 0))
        
        diff = ryan - apeach
        if diff <= max_diff:
            continue
            
        max_diff = diff
        answer = [num_arrow + 1 if ryan_won else 0 for (num_arrow, ryan_won) in zip(info, case)]
        answer[0] = n - total_arrows

    answer.reverse()
    return answer