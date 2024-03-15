from collections import Counter

def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()
    
    def generate_substrings(s):
        return [s[i:i+2] for i in range(len(s) - 1) if s[i:i+2].isalpha()]
    
    m1 = Counter(generate_substrings(str1))
    m2 = Counter(generate_substrings(str2))
    
    intersection = sum((m1 & m2).values())
    union = sum((m1 | m2).values())
    
    if union == 0:
        return 65536
    
    similarity = intersection / union
    return int(similarity * 65536)