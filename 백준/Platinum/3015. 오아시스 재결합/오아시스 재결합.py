input = open(0).readline

N = int(input())
stack = [(float('inf'), 0)]

ans = 0
for _ in range(N):
    height = int(input())
    same_cnt = 1
    while stack[-1][0] <= height:
        ans += stack[-1][1]  # 앞선 사람들이 이룬 짝은 나도 이룰 수 있음
        if stack[-1][0] == height:
            same_cnt += stack[-1][1]
            
        stack.pop()

    if len(stack) > 1:
        ans += 1  # 내 앞에 키 큰 사람과 짝
    
    stack.append((height, same_cnt))
    
print(ans)