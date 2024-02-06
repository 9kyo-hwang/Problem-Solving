input = open(0).readline

n = int(input())
numbers = sorted([int(input()) for _ in range(n)])

if n == 0:
    print(0)
else:
    trim_count = round(n * 0.15 + 0.00000000001)
    trimmed = numbers[trim_count:n - trim_count]
    
    if len(trimmed) == 0:
        print(0)
    else:
        print(round(sum(trimmed) / len(trimmed) + 0.00000000001))