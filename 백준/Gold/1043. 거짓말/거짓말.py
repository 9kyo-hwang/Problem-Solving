input = open(0).readline

N, M = map(int, input().split())

parents = [i for i in range(N + 1)]

know_trues = list(map(int, input().split()))[1:]

for know in know_trues:
    parents[know] = 0

parties = [list(map(int, input().split()))[1:] for _ in range(M)]
    

def find(x: int) -> int:
    while x != parents[x]:
        parents[x] = parents[parents[x]]
        x = parents[x]
    return parents[x]
    

def union(x: int, y: int):
    x = find(x)
    y = find(y)
    
    if x == y:
        return
    
    if x < y:
        parents[y] = x
    elif x > y:
        parents[x] = y
        

for party in parties:
    for i in range(len(party) - 1):
        union(party[i], party[i + 1])


answer = sum(not any(find(member) == 0 for member in party) for party in parties)
print(answer)