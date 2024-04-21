from collections import deque
input = open(0).readline


def out_of_bound(N: int, tile: list, x: int, y: int) -> bool:
    return not(0 <= x < N and 0 <= y < N * 2 and 1 <= tile[x][y] <= 6)


def pos_to_num(N: int, x: int, y: int) -> int:
    y += 1 if x & 1 else 2
    y >>= 1
    return y + x * N - x // 2
    

def bfs(N: int, tile: list, parents: list) -> tuple:
    q = deque([(0, 0, 1)])
    visited = [False] * (pos_to_num(N, N, N * 2) + 1)
    visited[pos_to_num(N, 0, 0)] = True
    offset = [(-1, 1), (0, 2), (1, 1), (1, -1), (0, -2), (-1, -1)]
    
    max_t, max_d = 0, 0
    while q:
        x, y, d = q.popleft()
        t = pos_to_num(N, x, y)
        
        if t > max_t:
            max_t = t
            max_d = d
            
        
        for d, (dx, dy) in enumerate(offset):
            nx, ny = x + dx, y + dy
            nt = pos_to_num(N, nx, ny)
            if out_of_bound(N, tile, nx, ny) or visited[nt]:
                continue
                
            if d // 3 == 0 and tile[x][y + 1] != tile[nx][ny]:
                continue
            elif d // 3 == 1 and tile[x][y] != tile[nx][ny + 1]:
                continue
                
            visited[nt] = True
            parents[nt] = t
            q.append((nx, ny, d + 1))
    
    
    return (max_t, max_d)


def dfs(parents: list, tile: int):
    if parents[tile] == tile:
        return
    
    dfs(parents, parents[tile])
    print(tile, end=' ')


def main():
    N = int(input())
    tile = [[0] * (N * 2) for _ in range(N)]
    
    for i in range(N):
        if i & 1:
            for j in range(1, N * 2 - 1, 2):
                tile[i][j], tile[i][j + 1] = map(int, input().split())
        else:
            for j in range(0, N * 2, 2):
                tile[i][j], tile[i][j + 1] = map(int, input().split())
                
    
    parents = [0] * (pos_to_num(N, N, N * 2) + 1)
    max_t, max_d = bfs(N, tile, parents)
    
    print(max_d)
    dfs(parents, max_t)


if __name__ == "__main__":
    main()