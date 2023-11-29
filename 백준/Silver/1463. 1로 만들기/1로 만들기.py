input = open(0).readline

X = int(input())
dp = {1: 0}

def memoization(x):
    if x <= 1: return 0
    
    if x in dp.keys(): return dp[x]
    
    if (x % 3 == 0) and (x % 2 == 0): dp[x] = min(memoization(x // 3), memoization(x // 2)) + 1
    elif x % 3 == 0: dp[x] = min(memoization(x // 3), memoization(x - 1)) + 1
    elif x % 2 == 0: dp[x] = min(memoization(x // 2), memoization(x - 1)) + 1
    else: dp[x] = memoization(x - 1) + 1
    
    return dp[x]
    
print(memoization(X))