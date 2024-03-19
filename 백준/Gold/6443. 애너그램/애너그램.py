input = open(0).readline

for _ in range(int(input())):
    chars = sorted(input().rstrip())
    char_dict = {}
    for char in chars:
        if char not in char_dict:
            char_dict[char] = 1
        else:
            char_dict[char] += 1
    
    def backtracking(anagram = "", select = 0):
        if select == len(chars):
            print(anagram)
            return
        
        for char, cnt in char_dict.items():
            if cnt == 0:
                continue
            
            char_dict[char] -= 1
            backtracking(anagram + char, select + 1)
            char_dict[char] += 1
            
    backtracking()