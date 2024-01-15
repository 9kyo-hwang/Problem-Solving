input = open(0).readline

N = int(input())

lst = list()
for _ in range(N):
    begin, end = map(int, input().split())
    lst.append((end, begin))
    
lst.sort()

time, cnt = 0, 0
for end, begin in lst:
    if begin >= time:
        time = end
        cnt += 1
        
print(cnt)