def solution(x):
    y = x
    sum_x = 0
    while x > 0:
        sum_x += x % 10
        x //= 10
    
    return y % sum_x == 0