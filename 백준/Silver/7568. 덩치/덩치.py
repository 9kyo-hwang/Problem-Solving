input = open(0).readline

N: int = int(input())
lst = [tuple(map(int, input().split())) for _ in range(N)]

for x1, y1 in lst:
    rank: int = 1
    for x2, y2 in lst:
        if x1 < x2 and y1 < y2:
            rank += 1
    print(rank, end=' ')