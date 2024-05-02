from itertools import permutations
input = open(0).readline

A, B = input().split()
list_A, num_B = list(A), int(B)

ans = -1
for perm in permutations(list_A, len(list_A)):
    if(perm[0] == '0'):
        continue
    
    num_A = int(''.join(perm))
    if num_A < num_B:
        ans = max(ans, num_A)
        
print(ans)