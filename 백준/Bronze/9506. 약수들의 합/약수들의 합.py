while True:
    N = int(input())
    if N == -1:
        break
        
    L = [1]
    for div in range(2, int(N**(1/2)) + 1):
        if N % div == 0:
            L.extend((div, N//div))
    
    print(f"{N} is NOT perfect." if sum(L) != N else f"{N} = {' + '.join(map(str, sorted(L)))}")