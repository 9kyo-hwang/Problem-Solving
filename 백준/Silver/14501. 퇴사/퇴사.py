input = open(0).readline

N = int(input())
TP = [tuple(map(int, input().split())) for _ in range(N)]

def recursion(day: int = 0, revenue: int = 0):
    if day == N:
        return revenue
    elif day > N:
        return 0
    else:
        T, P = TP[day]
        return max(recursion(day + T, revenue + P), recursion(day + 1, revenue))

print(recursion())