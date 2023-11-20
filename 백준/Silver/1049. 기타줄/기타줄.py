input = open(0).readline

N, M = map(int, input().split())

min_bundle, min_each = 1001, 1001
for i in range(M):
    bundle, each = map(int, input().split())
    
    min_bundle = min(min_bundle, bundle)
    min_each = min(min_each, each)


if min_bundle > min_each * 6:
    print(min_each * N)
else:
    answer = min_bundle * (N // 6)
    answer += min_bundle if min_each * (N % 6) > min_bundle else min_each * (N % 6)
    print(answer)