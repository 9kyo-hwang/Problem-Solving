def solution(s):
    answer = 0
    for ch in s:
        if answer < 0:
            break
        
        if ch == '(':
            answer += 1
        elif ch == ')':
            answer -= 1
    return answer == 0