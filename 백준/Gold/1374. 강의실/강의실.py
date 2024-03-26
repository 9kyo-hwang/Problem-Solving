from heapq import *
input = open(0).readline

N = int(input())
lectures = [tuple(map(int, input().split())) for _ in range(N)]
lectures.sort(key=lambda lecture: (lecture[1], lecture[2]))

room = [0]  # 강의 종료 시간 기록
for _, begin, end in lectures:
    if room[0] <= begin:  # 가장 빨리 끝나는 종료 시간 <= 강의 시작 시간
        heappop(room)
        
    heappush(room, end)
    
print(len(room))