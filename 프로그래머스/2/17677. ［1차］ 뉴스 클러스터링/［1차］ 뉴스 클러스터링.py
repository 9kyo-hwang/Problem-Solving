from collections import Counter

def solution(str1, str2):
    m1 = Counter([str1[i:i+2].lower() for i in range(len(str1) - 1) if str1[i:i+2].isalpha()])
    m2 = Counter([str2[i:i+2].lower() for i in range(len(str2) - 1) if str2[i:i+2].isalpha()])
    
    intersection = sum((m1 & m2).values())
    union = sum((m1 | m2).values())
    
    if union == 0:
        return 65536
    
    similarity = intersection / union
    return int(similarity * 65536)