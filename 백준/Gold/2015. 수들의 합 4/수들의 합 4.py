from collections import defaultdict
input = open(0).readline

N, K = map(int, input().split())
A = list(map(int, input().split()))
prefix_sum = [0] * (N + 1)

ans = 0
for i in range(1, N + 1):
    prefix_sum[i] = prefix_sum[i - 1] + A[i - 1]
    if prefix_sum[i] == K:
        ans += 1
    
cnt = defaultdict(int)
for i in range(1, N + 1):
    ans += cnt[prefix_sum[i] - K]
    cnt[prefix_sum[i]] += 1
    
print(ans)