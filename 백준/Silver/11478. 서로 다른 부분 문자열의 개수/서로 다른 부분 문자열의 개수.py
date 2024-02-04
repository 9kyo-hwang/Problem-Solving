S = open(0).readline().rstrip()
ans = 0
for i in range(len(S)):
    substr = set()
    for j in range(len(S) - i):
        substr.add(S[j:i+j+1])
    ans += len(substr)
print(ans)