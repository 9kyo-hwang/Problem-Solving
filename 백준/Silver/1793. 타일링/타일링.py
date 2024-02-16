input = open(0).readline

dp = [1] * 251
for i in range(2, 251):
    dp[i] = dp[i - 1] + 2 * dp[i - 2]
    
while True:
    try:
        print(dp[int(input())])
    except:
        break