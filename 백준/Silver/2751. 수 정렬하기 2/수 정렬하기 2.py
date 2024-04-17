import random
input = open(0).readline

N = int(input())
arr = [int(input()) for _ in range(N)]

def quicksort(arr: list) -> list:
    if len(arr) <= 1:
        return arr
        
    pivot = arr[random.randrange(0, len(arr) - 1)]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return quicksort(left) + middle + quicksort(right)
    
print(*quicksort(arr))