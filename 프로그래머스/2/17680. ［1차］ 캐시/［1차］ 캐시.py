from collections import deque

HIT = 1
MISS = 5

def solution(cache_size, cities):
    cache = deque()
    time = 0
    
    for city in cities:
        city = city.lower()
        
        if city in cache:
            time += HIT
            cache.remove(city)
            cache.append(city)
        else:
            time += MISS
            cache.append(city)
            if len(cache) > cache_size:
                cache.popleft()
        
    return time