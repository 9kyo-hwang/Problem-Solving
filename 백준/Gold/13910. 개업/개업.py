from collections import deque
input = open(0).readline

N, M = map(int, input().split())
S = list(map(int, input().split()))
S = set(S + [S[i] + S[j] for i in range(M - 1) for j in range(i + 1, M) if S[i] + S[j] <= N])

counts = [-1] * (N + 1)
q = deque()

for wok in S:  # start node
    counts[wok] = 1
    q.append(wok)
    
while q:
    cook = q.popleft()
    for wok in S:  # distance == node
        if cook + wok > N or counts[cook + wok] > -1:
            continue
        
        counts[cook + wok] = counts[cook] + 1
        q.append(cook + wok)
        
print(counts[N])