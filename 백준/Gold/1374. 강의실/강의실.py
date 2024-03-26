from heapq import *
input = open(0).readline

N = int(input())
lectures = [tuple(map(int, input().split())) for _ in range(N)]
lectures.sort(key=lambda lecture: (lecture[1], lecture[2]))

room = []
for num, s, t in lectures:
    if not room:
        heappush(room, t)
        continue
    
    if room[0] <= s:
        heappop(room)
        
    heappush(room, t)
    
print(len(room))