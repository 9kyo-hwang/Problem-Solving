A, P = map(int, input().split())

visited = {}

while True:
    if A not in visited:
        visited[A] = 1
    elif visited[A] == 2:
        break
    else:
        visited[A] += 1
    
    digits = list(map(int, str(A)))
    A = sum(x ** P for x in digits)
    
    
print(sum(value == 1 for value in visited.values()))