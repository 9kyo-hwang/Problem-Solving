input = open(0).readline

N = int(input())

count = 0
while N > 0 and N % 5 != 0:
    N -= 3
    count += 1
count += N // 5

print(count if N >= 0 else -1)