N, M = map(int, input().split())
lst = sorted(list(map(int, input().split())))

def backtracking(selected, index = 0):
    if len(selected) == M:
        print(*selected)
        return
    
    for i in range(index, N):
        selected.append(lst[i])
        backtracking(selected, i + 1)
        selected.pop()
        
        
backtracking([])