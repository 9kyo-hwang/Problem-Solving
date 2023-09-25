import re

def divide(x):
    m = re.match('([a-zA-Z \.-]+)([0-9]{1,5})(.*)', x)
    head, number, tail = m.groups()
    return head, number, tail

def solution(files):
    for k, file in enumerate(files):
        files[k] = [file, divide(file)]
        
    answer = sorted(files, key = lambda x: (
        x[1][0].lower(),
        int(x[1][1])
    ))
    
    for k, v in enumerate(answer):
        answer[k] = v[0]
        
    return answer