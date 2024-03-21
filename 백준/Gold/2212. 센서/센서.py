input = open(0).readline

N = int(input())
K = int(input())
sensors = sorted(map(int, input().split()))
dist_btwn_sensors = sorted([snd - fst for fst, snd in zip(sensors, sensors[1:])])

print(sum(dist_btwn_sensors[:N - K]))