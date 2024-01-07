from collections import deque

input = open(0).readline

R, C = map(int, input().split())
lake = list(input().strip() for _ in range(R))

water_pos = deque()
is_water_space = [[False for _ in range(C)] for _ in range(R)]
swan_pos = deque()

for i, r in enumerate(lake):
    for j, c in enumerate(r):
        if c == 'X':
            continue
        
        water_pos.append((i, j))
        is_water_space[i][j] = True
        
        if c == 'L':
            swan_pos.append((i, j))
            

parents = [i for i in range(R * C)]
rank = [0] * (R * C)

offset = [(-1, 0), (0, 1), (1, 0), (0, -1)]


def out_of_bound(x, y):
    return x < 0 or x >= R or y < 0 or y >= C


def convert_coord(x, y):
    return x * C + y


def find(x):
    while x != parents[x]:
        parents[x] = parents[parents[x]]
        x = parents[x]
    return parents[x]


def union(x, y):
    root_x, root_y = find(x), find(y)
    
    if rank[root_x] > rank[root_y]:
        parents[root_y] = root_x
        rank[root_x] += rank[root_y]
    else:
        parents[root_x] = root_y
        rank[root_y] += rank[root_x]


days = 0
while swan_pos:
    for x, y in water_pos:
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            if out_of_bound(nx, ny) or is_water_space[nx][ny] == False:
                continue
            
            union(convert_coord(x, y), convert_coord(nx, ny))
            
    if find(convert_coord(*swan_pos[0])) == find(convert_coord(*swan_pos[1])):
        break
    
    size = len(water_pos)
    for _ in range(size):
        x, y = water_pos.popleft()
        
        for dx, dy in offset:
            nx, ny = x + dx, y + dy
            if out_of_bound(nx, ny) or is_water_space[nx][ny] == True:
                continue
            
            is_water_space[nx][ny] = True
            water_pos.append((nx, ny))
            
    days += 1

print(days)