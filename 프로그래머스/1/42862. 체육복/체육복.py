def solution(n, lost, reserve):
    sweatsuits = [0] * (n + 2)
    
    for l in lost: sweatsuits[l] -= 1
    for r in reserve: sweatsuits[r] += 1
    
    for i in range(1, n + 1):
        if sweatsuits[i] != -1: continue
            
        if sweatsuits[i - 1] == 1: sweatsuits[i - 1] = sweatsuits[i] = 0
        elif sweatsuits[i + 1] == 1: sweatsuits[i] = sweatsuits[i + 1] = 0
    
    return sum(sweatsuit != -1 for sweatsuit in sweatsuits[1 : n + 1])