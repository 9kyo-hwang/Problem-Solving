input = open(0).readline

N, M = map(int, input().split())

min_bundle, min_each = 1001, 1001

for i in range(M):
    bundle, each = map(int, input().split())
    min_bundle, min_each = min(min_bundle, bundle), min(min_each, each)

print(min_each * N if min_bundle > min_each * 6 else min_bundle * (N // 6) + min(min_bundle, min_each * (N % 6)))