input = open(0).readline

N, M = map(int, input().split())  # 개수, 요구 메모리
m = list(map(int, input().split()))  # 메모리
c = list(map(int, input().split()))  # 비용

MAX_COST = 10**4

max_memories = [0] * (MAX_COST + 1)  # 각 코스트 별 최대 메모리 사용량
for memory, cost in zip(m, c):
    for max_cost in range(MAX_COST, cost - 1, -1):
        max_memories[max_cost] = max(max_memories[max_cost], max_memories[max_cost - cost] + memory)
        

ans = 0
for cost, max_memory in enumerate(max_memories):
    if max_memory >= M:
        ans = cost
        break
    
print(ans)