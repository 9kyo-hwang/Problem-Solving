from itertools import combinations

input = open(0).readline

while (S := list(map(str, input().split()))) and S[0] != 0:
    for comb in combinations(S[1:], 6):
        print(' '.join(comb))
    print()