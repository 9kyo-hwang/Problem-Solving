input = open(0).readline

N, S = map(int, input().split())
nums = list(map(int, input().split()))

def powerset(index: int = 0, total: int = 0) -> int:
    if index >= N:
        return total == S
    
    return powerset(index + 1, total + nums[index]) + powerset(index + 1, total)
    

count = powerset()
if S == 0:
    count -= 1
print(count)