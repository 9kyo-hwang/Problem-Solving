input = open(0).readline

def check(buffer: str) -> bool:
    stack = []
    for ch in buffer:
        if ch == '(' or ch == '[':
            stack.append(ch)
        elif ch == ')' or ch == ']':
            if not stack:
                return False
            
            if (stack[-1] == '(' and ch == ']') or (stack[-1] == '[' and ch == ')'):
                return False
                
            stack.pop()
            
    return not stack

while (buffer := input().rstrip()) and buffer != '.':
    print('yes' if check(buffer) else 'no')