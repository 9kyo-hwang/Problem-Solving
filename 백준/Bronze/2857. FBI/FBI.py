input = open(0).readline

result = []
for i in range(1, 6):
    is_agent = (input().rstrip().find('FBI') != -1)
    if is_agent:
        result.append(i)
        

if not result:
    print("HE GOT AWAY!")
else:
    print(*result)