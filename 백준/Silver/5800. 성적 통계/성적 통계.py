input = open(0).readline

K = int(input())
for X in range(1, K + 1):
    N = list(map(int, input().split()))
    grade = sorted(N[1:])
    
    maxi = max(grade)
    mini = min(grade)
    gap = max([grade[i + 1] - grade[i] for i in range(len(grade) - 1)])
    
    print('Class {}'.format(X))
    print('Max {}, Min {}, Largest gap {}'.format(maxi, mini, gap))