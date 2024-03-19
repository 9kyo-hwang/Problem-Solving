input = open(0).readline

N = int(input())

while N % 2 == 0:
    print(2)
    N //= 2
    
for i in range(3, int(N**0.5) + 1, 2):
    while N % i == 0:
        print(i)
        N //= i
        
if N > 2:
    print(N)