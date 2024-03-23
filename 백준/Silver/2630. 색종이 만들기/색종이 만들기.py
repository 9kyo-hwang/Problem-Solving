input = open(0).readline

n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]
color_cnt = [0, 0]

def get_confetti_cnt(size: int, x: int, y: int):
    color = paper[x][y]
    if size == 1:
        color_cnt[color] += 1
        return
    
    for i in range(x, x + size):
        for j in range(y, y + size):
            if paper[i][j] != color:
                get_confetti_cnt(size // 2, x, y)
                get_confetti_cnt(size // 2, x, y + size // 2)
                get_confetti_cnt(size // 2, x + size // 2, y)
                get_confetti_cnt(size // 2, x + size // 2, y + size // 2)
                return

    color_cnt[color] += 1

get_confetti_cnt(n, 0, 0)

print(*color_cnt, sep='\n')