from itertools import combinations
input = open(0).readline

N = int(input())
table = [list(map(int, input().split())) for _ in range(N)]
members = list(range(N))

ans = float('inf')
for start_members in combinations(members, N // 2):
    start, link = 0, 0
    link_members = list(set(members) - set(start_members))
    
    for m1, m2 in combinations(start_members, 2):
        start += table[m1][m2]
        start += table[m2][m1]
    
    for m1, m2 in combinations(link_members, 2):
        link += table[m1][m2]
        link += table[m2][m1]
        
    ans = min(ans, abs(start - link))
    
print(ans)