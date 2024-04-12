n = int(input())
dp = [-1] * (n + 1)

def fib(num: int = n) -> int:
    if num < 2:
        return num
    elif dp[num] > -1:
        return dp[num]
    else:
        dp[num] = fib(num - 1) + fib(num - 2)
        return dp[num]
        
print(fib())