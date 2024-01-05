input = open(0).readline

n = int(input())
lst = sorted(list(map(int, input().split())))
x = int(input())

left, right = 0, n - 1
count = 0

while left < right:
    current = lst[left] + lst[right]
    
    if current < x:
        left += 1
    elif current > x:
        right -= 1
    else:
        count += 1
        left += 1
        right -= 1
        
print(count)