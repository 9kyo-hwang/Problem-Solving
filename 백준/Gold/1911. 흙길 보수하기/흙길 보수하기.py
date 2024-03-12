input = open(0).readline

N, L = map(int, input().split())
pools = sorted([tuple(map(int, input().split())) for _ in range(N)])

prev_plank_end, ans = pools[0][0], 0
for begin, end in pools:
    if prev_plank_end > end:
        continue
    
    prev_plank_end = max(prev_plank_end, begin)
    plank_cnt = (end - prev_plank_end) // L + ((end - prev_plank_end) % L > 0)
    
    ans += plank_cnt
    prev_plank_end += plank_cnt * L

print(ans)