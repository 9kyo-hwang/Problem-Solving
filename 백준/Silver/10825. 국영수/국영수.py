input = open(0).readline

scores = list()
for _ in range(int(input())):
    name, kor, eng, math = input().split()
    kor, eng, math = int(kor), int(eng), int(math)
    scores.append((-kor, eng, -math, name))
    
print(*map(lambda x: x[3], sorted(scores)), sep='\n')