input = open(0).readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

arr = []
i, j = 0, 0
while i < N and j < M:
    if A[i] < B[j]:
        arr.append(A[i])
        i += 1
    else:
        arr.append(B[j])
        j += 1
        
while i < N:
    arr.append(A[i])
    i += 1
    
while j < M:
    arr.append(B[j])
    j += 1
    
print(*arr)