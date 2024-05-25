N = int(input())
size = list(map(int, input().split()))

prev, score = 0, 0
for i in range(N - 1):
    prev += size[i]
    score += prev * size[i + 1]
print(score)