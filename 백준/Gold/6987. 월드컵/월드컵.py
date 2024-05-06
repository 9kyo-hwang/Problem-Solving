from itertools import combinations
input = open(0).readline

matches = list(combinations(range(6), 2))
result_indices = ((0, 2), (1, 1), (2, 0))

def backtracking(game: int = 0) -> bool:
    if game == len(matches):
        for score in scores:
            if score.count(0) != 3:
                return False
                
        return True
    
    t1, t2 = matches[game]
    
    for i, j in result_indices:
        if scores[t1][i] <= 0 or scores[t2][j] <= 0:
            continue
        
        scores[t1][i] -= 1
        scores[t2][j] -= 1
        
        if backtracking(game + 1):
            return True
        
        scores[t1][i] += 1
        scores[t2][j] += 1
    
    return False

for _ in range(4):
    scores = list(map(int, input().split()))
    scores = [scores[i:i+3] for i in range(0, 18, 3)]
    print(1 if backtracking() else 0, end=' ')