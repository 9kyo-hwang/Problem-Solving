input = open(0).readline

N = int(input())
stack = []

for _ in range(N):
    cmd = list(map(int, input().split()))
    
    if cmd[0] == 1:
        stack.append(cmd[1])
    elif cmd[0] == 2:
        print(-1 if not stack else stack.pop())
    elif cmd[0] == 3:
        print(len(stack))
    elif cmd[0] == 4:
        print(1 if not stack else 0)
    elif cmd[0] == 5:
        print(-1 if not stack else stack[-1])