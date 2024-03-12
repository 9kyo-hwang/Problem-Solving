input = open(0).readline

N, L = map(int, input().split())
pools = sorted([tuple(map(int, input().split())) for _ in range(N)])

prev_plank_end, ans = 0, 0
for begin, end in pools:
    real_begin = max(prev_plank_end, begin)
    while real_begin < end:
        real_begin += L
        ans += 1
    prev_plank_end = real_begin

print(ans)