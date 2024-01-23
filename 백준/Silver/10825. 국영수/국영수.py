input = open(0).readline

N = int(input())
scores = [input().split() for _ in range(N)]
scores.sort(key=lambda x : (-int(x[1]), int(x[2]), -int(x[3]), x[0]))
print(*[name for name, _, _, _ in scores], sep='\n')