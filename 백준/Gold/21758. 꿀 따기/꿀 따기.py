input = open(0).readline

N = int(input())
honeys = [0] + list(map(int, input().split()))

prefix_sum = [0] * (N + 1)
for i in range(1, N + 1):
    prefix_sum[i] = prefix_sum[i - 1] + honeys[i]

ans = 0
for i in range(2, N):  # 벌(1) - 벌(i) - 벌통(N)
    fst = prefix_sum[N] - honeys[1] - honeys[i]
    snd = prefix_sum[N] - prefix_sum[i]
    ans = max(ans, fst + snd)
    
for i in range(2, N):  # 벌통(1) - 벌(i) - 벌(N)
    fst = prefix_sum[i - 1]
    snd = prefix_sum[N - 1] - honeys[i]
    ans = max(ans, fst + snd)
    
for i in range(2, N):  # 벌(1) - 벌통(i) - 벌(N)
    fst = prefix_sum[i] - honeys[1]
    snd = prefix_sum[N - 1] - prefix_sum[i - 1]
    ans = max(ans, fst + snd)
    
print(ans)