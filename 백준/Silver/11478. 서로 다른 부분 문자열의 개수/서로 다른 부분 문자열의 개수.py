S = open(0).readline().rstrip()
substr_set = {S[i:j + 1] for i in range(len(S)) for j in range(i, len(S))}
print(len(substr_set))