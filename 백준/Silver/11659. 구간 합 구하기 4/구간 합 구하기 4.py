input = open(0).readline

N, M = map(int, input().split())

nums = [0] + list(map(int, input().split()))
for i in range(1, N + 1):
    nums[i] += nums[i - 1]

for _ in range(M):
    i, j = map(int, input().split())
    print(nums[j] - nums[i - 1])