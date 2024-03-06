from collections import deque

def solution(priorities, location):
    q = deque(enumerate(priorities))
    answer = 1
    
    while True:
        top_loc, top_p = max(q, key=lambda x:x[1])
        front_loc, front_p = q.popleft()
        
        if top_p > front_p:
            q.append((front_loc, front_p))
        elif front_loc == location:
            break
        else:
            answer += 1
            
    return answer