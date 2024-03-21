input = open(0).readline

r, c, k = map(int, input().split())
r, c = r - 1, c - 1
A = [list(map(int, input().split())) for _ in range(3)]


def calculation(lst, d):
    sorted_list = []
    max_cnt = 0
    
    for row in lst:
        cnts = {col : row.count(col) for col in row if col != 0}
        cnts_list = sorted(cnts.items(), key=lambda x: (x[1], x[0]))
        flatten = [item for items in cnts_list for item in items]
        sorted_list.append(flatten)
        max_cnt = max(max_cnt, len(flatten))
    
    for row in sorted_list:
        row += [0] * (max_cnt - len(row))
        row = row[:100]
        
    return sorted_list if d == 'r' else list(zip(*sorted_list))
    

ans = -1
for tick in range(0, 101):
    if r < len(A) and c < len(A[0]):
        if A[r][c] == k:
            ans = tick
            break
    
    if len(A) >= len(A[0]):
        A = calculation(A, "r")
    else:
        A = calculation(list(zip(*A)), "c")
        
print(ans)