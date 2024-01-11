input = open(0).readline

N = int(input())
words = sorted(sorted(set([input().strip() for _ in range(N)])), key = len)

print('\n'.join(words))