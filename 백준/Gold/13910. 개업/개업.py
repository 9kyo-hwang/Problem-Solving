from collections import deque
input = open(0).readline

N, M = map(int, input().split())
S = list(map(int, input().split()))
S = S + [S[i] + S[j] for i in range(M - 1) for j in range(i + 1, M) if S[i] + S[j] <= N]

counts = [-1] * (N + 1)
q = deque()

for wok_size in S:  
    counts[wok_size] = 1
    q.append(wok_size)
    
while q:
    current_num_noodle = q.popleft()
    if current_num_noodle == N:
        break
    
    for wok_size in S:  # distance == node
        next_num_noodle = current_num_noodle + wok_size
        if next_num_noodle > N or counts[next_num_noodle] > -1:
            continue
        
        counts[next_num_noodle] = counts[current_num_noodle] + 1
        q.append(next_num_noodle)
        
print(counts[N])