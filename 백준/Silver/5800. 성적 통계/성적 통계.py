input = open(0).readline

K = int(input())
for X in range(1, K + 1):
    N = sorted(list(map(int, input().split()))[1:])
    
    maxi = max(N)
    mini = min(N)
    gap = max([N[i + 1] - N[i] for i in range(len(N) - 1)])
    
    print('Class {}'.format(X))
    print('Max {}, Min {}, Largest gap {}'.format(maxi, mini, gap))