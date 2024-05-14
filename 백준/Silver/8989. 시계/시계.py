input = open(0).readline
HOUR_ANGLE = 30
MINUTE_ANGLE = 6

for _ in range(T := int(input())):
    times = tuple(input().split())
    angles = [0] * 5
    
    for i, time in enumerate(times):
        hour, minute = map(int, time.split(':'))
        hour %= 12
            
        hour_angle = hour * HOUR_ANGLE + minute * HOUR_ANGLE / 60
        minute_angle = minute * MINUTE_ANGLE
        
        maxi, mini = max(hour_angle, minute_angle), min(hour_angle, minute_angle)
        angle = min(maxi - mini, mini + 360 - maxi)
        angles[i] = angle

    print(sorted(zip(angles, times))[2][1])