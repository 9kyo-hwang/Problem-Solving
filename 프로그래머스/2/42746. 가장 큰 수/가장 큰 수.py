from functools import cmp_to_key

def solution(numbers):
    def comparator(x, y):
        a = str(x) + str(y)
        b = str(y) + str(x)
        
        if a < b:
            return 1
        elif a > b:
            return -1
        else:
            return 0
    
    numbers.sort(key=cmp_to_key(comparator))
    ans = ''.join(map(str, numbers))
    return '0' if ans[0] == '0' else ans