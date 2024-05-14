input = open(0).readline
HOUR_ANGLE = 360 // 12
MINUTE_ANGLE = 360 // 60

hour_angles = {hour : hour * HOUR_ANGLE for hour in range(12)}
minute_angles = {minute : minute * MINUTE_ANGLE for minute in range(60)}

for _ in range(T := int(input())):
    str_times = list(input().split())
    times = [list(map(int, time.split(':'))) for time in str_times]
    angles = [0] * 5
    
    for i, (hour, minute) in enumerate(times):
        if hour >= 12:
            hour -= 12
        
        hour_angle = hour_angles[hour] + minute * HOUR_ANGLE / 60
        minute_angle = minute_angles[minute]
        
        max_angle, min_angle = max(hour_angle, minute_angle), min(hour_angle, minute_angle)
        angle = min(max_angle - min_angle, min_angle + 360 - max_angle)
        angles[i] = angle
        
    print(sorted(zip(angles, str_times))[2][1])