input = open(0).readline

for _ in range(int(input())):
    time_dict = {}
    for t in list(input().rstrip().split(',')):
        condition, time = t.split(':')
        time_dict[condition] = int(time)
    
    comb_set = set()
    for c in list(input().rstrip().split('|')):
        comb_set.add(tuple(c.split('&')))
    
    ans = float('inf')
    for comb in comb_set:
        total_time = max(time_dict[condition] for condition in comb)
        ans = min(ans, total_time)
    
    print(ans)