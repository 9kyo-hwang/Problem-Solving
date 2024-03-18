input = open(0).readline
INF = float('inf')

n, m = int(input()), int(input())
adj_mat = [[INF] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    adj_mat[i][i] = 0
    
for _ in range(m):
    a, b, c = map(int, input().split())
    adj_mat[a][b] = min(adj_mat[a][b], c)
    
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j])
            
for i in range(1, n + 1):
    print(' '.join([str(0 if adj_mat[i][j] == INF else adj_mat[i][j]) for j in range(1, n + 1)]))