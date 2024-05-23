from heapq import *
input = open(0).readline

N = int(input())
min_heap, max_heap = [()] * N, [()] * N
problem_levels = {}

for i in range(N):
    P, L = map(int, input().split())
    min_heap[i] = (L, P)
    max_heap[i] = (-L, -P)
    problem_levels[P] = L
    
heapify(min_heap)
heapify(max_heap)

def pop(mode: str):
    if mode == '1':
        while -max_heap[0][1] not in problem_levels or problem_levels[-max_heap[0][1]] != -max_heap[0][0]:
            heappop(max_heap)
        return -max_heap[0][1]
    elif mode == "-1":
        while min_heap[0][1] not in problem_levels or problem_levels[min_heap[0][1]] != min_heap[0][0]:
            heappop(min_heap)
        return min_heap[0][1]


for _ in range(M := int(input())):
    command = list(input().split())
    
    if command[0] == "recommend":
        print(pop(command[1]))
    elif command[0] == "add":
        P, L = int(command[1]), int(command[2])

        heappush(min_heap, (L, P))
        heappush(max_heap, (-L, -P))
        problem_levels[P] = L
    elif command[0] == "solved":
        P = int(command[1])
        del problem_levels[P]