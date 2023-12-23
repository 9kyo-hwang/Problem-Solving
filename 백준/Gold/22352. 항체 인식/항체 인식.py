input = open(0).readline

N, M = map(int, input().split())
SP1 = [list(map(int, input().split())) for _ in range(N)]
SP2 = [list(map(int, input().split())) for _ in range(N)]

info = next(((SP1[i][j], SP2[i][j], i, j) for i in range(N) for j in range(M) if SP1[i][j] != SP2[i][j]), None)

def flood_fill(before, after, x, y):
    if x < 0 or x >= N or y < 0 or y >= M or SP1[x][y] != before:
        return
    
    SP1[x][y] = after
    
    flood_fill(before, after, x - 1, y)
    flood_fill(before, after, x, y + 1)
    flood_fill(before, after, x + 1, y)
    flood_fill(before, after, x, y - 1)


if info != None:
    flood_fill(*info)

is_correct_vaccine = all(SP1[i][j] == SP2[i][j] for i in range(N) for j in range(M))
    
print('YES' if info == None or is_correct_vaccine else 'NO')