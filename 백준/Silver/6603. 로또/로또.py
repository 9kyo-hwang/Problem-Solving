from itertools import combinations

input = open(0).readline

while (lst := list(map(int, input().split()))) and lst[0] != 0:
    k, S = lst[0], lst[1:]
    for comb in combinations(S, 6):
        print(*comb)
    print()