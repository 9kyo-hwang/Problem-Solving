input = open(0).readline

N, M = map(int, input().split())
r, c, d = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(N)]
offset = ((-1, 0), (0, 1), (1, 0), (0, -1))


def out_of_bound(in_r: int, in_c: int) -> bool:
    return not (0 <= in_r < N and 0 <= in_c < M)


def is_there_a_blank_space() -> bool:
    for dr, dc in offset:
        nr, nc = r + dr, c + dc
        
        if not out_of_bound(nr, nc) and room[nr][nc] == 0:
            return True
            
    return False


cnt = 0
while True:
    # logic 1
    if room[r][c] == 0:
        room[r][c] = 2
        cnt += 1
        
    
    # logic 2
    if not is_there_a_blank_space():
        dr, dc = offset[(d + 2) % 4]
        nr, nc = r + dr, c + dc
        
        if not out_of_bound(nr, nc) and room[nr][nc] != 1:
            r, c = nr, nc
        else:
            break
    
    # Logic 3
    else:
        d = (d - 1) % 4
        dr, dc = offset[d]
        nr, nc = r + dr, c + dc
        
        if not out_of_bound(nr, nc) and room[nr][nc] == 0:
            r, c = nr, nc
            
print(cnt)