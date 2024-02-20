from heapq import *

def solution(n, works):
    heapify(works := [-work for work in works])
    for _ in range(min(n, abs(sum(works)))):
        heappush(works, heappop(works) + 1)
    return sum([work * work for work in works])