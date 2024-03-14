def solution(progresses, speeds):
    answer = []
    
    max_day = 0
    for progress, speed in zip(progresses, speeds):
        day = (99 - progress) // speed + 1
        if day > max_day:
            answer.append(1)
        else:
            answer[-1] += 1
        max_day = max(max_day, day)
    
    return answer