input = open(0).readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

arr = [0] * (N + M)
i, j, k = 0, 0, 0

while i < N and j < M:
    if A[i] < B[j]:
        arr[k] = A[i]
        k += 1
        i += 1
    else:
        arr[k] = B[j]
        k += 1
        j += 1
        
while i < N:
    arr[k] = A[i]
    k += 1
    i += 1
    
while j < M:
    arr[k] = B[j]
    k += 1
    j += 1
    
print(*arr)