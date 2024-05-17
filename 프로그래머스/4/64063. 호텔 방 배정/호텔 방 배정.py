import sys
sys.setrecursionlimit(10**6)

parents = {}

def find(x: int) -> int:
    if x not in parents:
        parents[x] = x + 1
        return x
    
    parents[x] = find(parents[x])
    return parents[x]

def solution(k, room_number):
    answer = []
    for room in room_number:
        answer.append(find(room))
    return answer