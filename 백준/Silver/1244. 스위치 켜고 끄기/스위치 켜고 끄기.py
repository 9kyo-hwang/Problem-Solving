input = open(0).readline

N = int(input())
switch = [0] + list(map(int, input().split()))

for _ in range(int(input())):
    sex, num = map(int, input().split())
    
    if sex == 1:
        for i in range(num, N + 1, num):
            switch[i] ^= 1
    elif sex == 2:
        switch[num] ^= 1
        
        begin, end = num - 1, num + 1
        while (1 <= begin and end <= N) and (switch[begin] == switch[end]):
            switch[begin] ^= 1
            switch[end] ^= 1
            
            begin -= 1
            end += 1
            

for i in range(1, N + 1):
    print(switch[i], end=' ')
    if i % 20 == 0:
        print()