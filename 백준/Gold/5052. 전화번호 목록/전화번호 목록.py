input = open(0).readline

for _ in range(int(input())):
    phone_numbers = sorted(input().rstrip() for _ in range(int(input())))
    
    def is_it_consistent():
        for fst, snd in zip(phone_numbers, phone_numbers[1:]):
            if len(fst) < len(snd) and fst == snd[:len(fst)]:
                return print('NO')
        
        return print('YES')
        
    is_it_consistent()