N = int(input())
A = set(map(int, input().split()))
M = int(input())
print('\n'.join('1' if num in A else '0' for num in map(int, input().split())))