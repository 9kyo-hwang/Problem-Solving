from math import floor
input = open(0).readline

def get_distance(a, b, c, d, v, m):
    return (a*v**3 + b*v**2 + c*v + d) * m

def binary_search(a, b, c, d, m, t):
    lo, hi = 1, 1000000
    ans = 0
    
    while lo <= hi:
        mid = (lo + hi) // 2  # 속력
        dist = get_distance(a, b, c, d, mid / 100, m)
        
        if dist <= t:
            ans = max(ans, mid)
            lo = mid + 1
        else:
            hi = mid - 1
            
    return ans

while True:
    try:
        a, b, c, d, m, t = map(float, input().split())
        v = binary_search(a, b, c, d, m, t)
        print("%.2f" % (v / 100))
    except:
        break