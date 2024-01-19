input = open(0).readline

def solve(txt):
    answer = 0
    for ch in txt:
        if answer < 0:
            return False
        
        if ch == '(':
            answer += 1
        elif ch == ')':
            answer -= 1
            
    return answer == 0


for _ in range(int(input())):
    print("YES" if solve(input().strip()) else "NO")